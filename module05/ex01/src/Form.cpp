#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

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

const std::string   Form::getName() const {return name;}
bool                Form::getIsSigned() const {return isSigned;}
int                 Form::getSignGrade() const {return signGrade;}
int                 Form::getExecGrade() const {return execGrade;}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > getSignGrade()) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return ("Grade is too High!");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("Grade is too Low!");
}

std::ostream& operator<<(std::ostream &os, const Form& f) {
    os << "Form: " << f.getName() << ", Signed: " << f.getIsSigned()
        << ", Grade Requirede to sign: " << f.getSignGrade()
        << ", Grade Required to execute: " << f.getExecGrade();
    return os;
}