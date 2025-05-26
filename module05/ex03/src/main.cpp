#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {
    Intern someRandomIntern;
    std::cout << "\n[TEST] 1\n";
    try {
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        delete rrf;
    } catch (const std::exception& e) {
        std::cerr << "Test 1 Error: " << e.what() << std::endl;
    }

    std::cout << "\n[TEST] 2\n";
    try {
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Alice");
        std::cout << *ppf << std::endl;
        delete ppf;
    } catch (const std::exception& e) {
        std::cerr << "Test 2 Error: " << e.what() << std::endl;
    }

    std::cout << "\n[TEST] 3\n";
    try {
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        std::cout << *scf << std::endl;
        delete scf;
    } catch (const std::exception& e) {
        std::cerr << "Test 3 Error: " << e.what() << std::endl;
    }

    std::cout << "\n[TEST] 4\n";
    try {
        AForm* unknown = someRandomIntern.makeForm("unknown form", "Target");
        delete unknown;
    } catch (const std::exception& e) {
        std::cerr << "Test 4 Expected error: " << e.what() << std::endl;
    }
}