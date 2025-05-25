#include "RobotomyRequestForm.hpp"
#include "../include/Form.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("home") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const {
    std::cout << "* BZZZZZZZ DRRRRRR *\n";
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully!\n";
    else
        std::cout << "Robotomy failed on " << target << ".\n";
}