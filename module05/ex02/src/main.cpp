#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
{
    std::cout << "\n[TEST] ShrubberyCreationForm\n";
    try {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm form("home");

        bob.signForm(form);
        bob.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
{
    std::cout << "\n[TEST] RobotomyRequestForm\n";
    try {
        Bureaucrat alice("Alice", 45);
        RobotomyRequestForm form("target1");

        alice.signForm(form);
        for (int i = 0; i < 5; ++i)
            alice.executeForm(form); // 50% chance success
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
{
    std::cout << "\n[TEST] PresidentialPardonForm\n";
    try {
        Bureaucrat zaphod("Zaphod", 1);
        PresidentialPardonForm form("Ford");

        zaphod.signForm(form);
        zaphod.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
}