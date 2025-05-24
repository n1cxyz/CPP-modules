#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
class Form;

class Bureaucrat
{
private:
    const std::string   name;
    int                 grade;
    
public:
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    Bureaucrat();
    Bureaucrat(const std::string   name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string   getName() const;
    int                 getGrade() const;
    void                incrementGrade(void);
    void                decrementGrade(void);

    void    signForm(Form& f);
};

std::ostream& operator<<(std::ostream &op, const Bureaucrat& b);

#endif