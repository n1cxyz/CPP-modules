#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm() : name("someForm"), isSigned(false), signGrade(100), execGrade(50) {}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) 
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
        if (signGrade < 1|| execGrade < 1) {
            throw GradeTooHighException();
        }
        if (signGrade > 150 || execGrade > 150) {
            throw GradeTooLowException();
        }
    }

AForm::AForm(const AForm& other) 
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const std::string   AForm::getName() const {return name;}
bool                AForm::getIsSigned() const {return isSigned;}
int                 AForm::getSignGrade() const {return signGrade;}
int                 AForm::getExecGrade() const {return execGrade;}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > getSignGrade()) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return ("Grade is too High!");
}

const char *AForm::GradeTooLowException::what() const throw() {
  return ("Grade is too Low!");
}

const char *AForm::FormNotSignedException::what() const throw() {
    return ("Form is not signed!");
}

std::ostream& operator<<(std::ostream &os, const AForm& f) {
    os << "Form: " << f.getName() << ", Signed: " << f.getIsSigned()
        << ", Grade Requirede to sign: " << f.getSignGrade()
        << ", Grade Required to execute: " << f.getExecGrade();
    return os;
}