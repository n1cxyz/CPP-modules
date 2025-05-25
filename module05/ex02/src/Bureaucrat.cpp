#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

Bureaucrat::Bureaucrat() : name("John"), grade(100) {}

Bureaucrat::Bureaucrat(const std::string   name, int grade) : name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
    : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string   Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade(void) {
    if (grade < 2) {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (grade > 149) {
        throw GradeTooLowException();
    }
    grade++;
}

void Bureaucrat::signForm(AForm& f) {
    try {
        f.beSigned(*this);
        std::cout << getName() << " signed " << f.getName() << "\n";
    } catch (const std::exception& e) {
        std::cout << getName() << " couldn't sign " << f.getName()
            << " because " << e.what() << "\n";
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << getName() << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is too Low!");
}

std::ostream& operator<<(std::ostream &op, const Bureaucrat& b) {
    op << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return op;
}