#include "Form.hpp"

Form::Form() : name("someForm"), isSigned(false), signGrade(100), execGrade(50) {}

Form::Form(const std::string name, const int signGrade, const int execGrade) 
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
        if (signGrade < 1|| execGrade < 1) {
            throw GradeTooHighException();
        }
        if (signGrade > 150 || execGrade > 150) {
            throw GradeTooLowException();
        }
    }

Form::Form(const Form& other) 
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form() {}

    const std::string   getName();
    bool                getIsSigned();
    const int           getSignGrade();
    const int           getExecGrade();

    void beSigned(Bureaucrat b);

std::ostream& operator<<(std::ostream &os, const Form& f) {
    os << "Form: " << f.getName() 
        << ", Grade Requirede to sign: " << f.getSignGrade()
        << ", Grade Required to execute: " << f.getExecGrade();
    return os;
}