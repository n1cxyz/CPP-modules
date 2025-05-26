#include "../include/Intern.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

const char* Intern::UnknownFormException::what() const throw() {
	return "unkown form requested";
}

AForm*	createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm*	createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm*	createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::makeForm(const std::string form, const std::string target) {
	std::string forms[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};

	AForm* (*creators[3])(const std::string&) = {
		createRobotomy,
		createPresidential,
		createShrubbery
	};

	for (int i = 0; i < 3; ++i) {
		if (form == forms[i]) {
			std::cout << "Intern creates " << form << std::endl;
			return creators[i](target);
		}
	}
	throw UnknownFormException();
}