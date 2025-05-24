#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class   Form 
{
private:
    const std::string   name;
    bool                isSigned;
    const int           signGrade;
    const int           execGrade;
public:
    class GradeTooHighException : std::exception {
        public:
            virtual const char* what() const throw() {
                return "Grade too high!";
            }
    };

    class GradeTooLowException : std::exception {
        public:
            virtual const char* what() const throw() {
                return "Grade too low!";
            }
    };

    Form();
    Form(const std::string name, const int signGrade, const int execGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string   getName();
    bool                getIsSigned();
    const int           getSignGrade();
    const int           getExecGrade();

    void beSigned(Bureaucrat b);
};

std::ostream& operator<<(std::ostream &os, const Form& f);

#endif