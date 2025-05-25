#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("home") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();

    std::ofstream file(target + "_shrubbery");
    if (!file) {
        std::cerr << "Could not open file for writing\n";
        return;
    }

    file << "       _-_\n"
         << "    /~~   ~~\\\n"
         << " /~~         ~~\\\n"
         << "{               }\n"
         << " \\  _-     -_  /\n"
         << "   ~  \\\\ //  ~\n"
         << "_- -   | | _- _\n"
         << "  _ -  | |   -_\n"
         << "      // \\\\\n";

    file.close();
}