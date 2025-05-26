#ifndef INTERN_HPP
# define INTERN_HPP

#include "../include/Form.hpp"

class Intern
{
private:
public:
	AForm*	makeForm(const std::string form, const std::string target);

	class UnknownFormException : public std::exception {
		public:
			const char* what() const throw();
	};
};

#endif