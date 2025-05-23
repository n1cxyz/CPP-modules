#include "Bureaucrat.hpp"

int main(void) {
   
   {
    try {
        Bureaucrat b("Bob", 0);
    } catch (const Bureaucrat::GradeTooHighException&) {
        std::cout << "Grade too high exception caught\n";
    } catch (...) {
        std::cout << "Unexpected exception type\n";
    }
   }
   {
    try {
        Bureaucrat b("Bob", 151);
    } catch (const Bureaucrat::GradeTooLowException&) {
        std::cout << "Grade too low exception caught\n";
    } catch (...) {
        std::cout << "Unexpected exception type\n";
    }
   }
   {
    try {
        Bureaucrat b("Dave", 1);
        b.incrementGrade();
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }
   }
    {
    try {
        Bureaucrat b("Dave", 150);
        b.decrementGrade();
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }
   }
   Bureaucrat b("Dave", 150);
   std::cout << b << "\n";
}