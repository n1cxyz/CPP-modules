#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
class Bureaucrat;

class   AForm 
{
private:
    const std::string   name;
    bool                isSigned;
    const int           signGrade;
    const int           execGrade;
public:
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    AForm();
    AForm(const std::string name, const int signGrade, const int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string   getName() const;
    bool                getIsSigned() const;
    int                 getSignGrade() const;
    int                 getExecGrade() const;

    virtual void beSigned(const Bureaucrat& b);
    virtual void execute(const Bureaucrat& executor) const;
    virtual void action() const = 0;
};

std::ostream& operator<<(std::ostream &os, const AForm& f);

#endif