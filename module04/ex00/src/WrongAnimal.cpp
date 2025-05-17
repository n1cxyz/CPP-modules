#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "constructor called from WrongAnimal" << std::endl;
	this->type = "WrongAnimal";
};

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal) {
	std::cout << "copy constructor called from WrongAnimal" << std::endl;
	this->type = WrongAnimal.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &WrongAnimal) {
	std::cout << "assignment overload overload called from WrongAnimal" << std::endl;
	if (this == &WrongAnimal) {
		return *this;
	}
	this->type = WrongAnimal.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor called from WrongAnimal" << std::endl;
};

void	WrongAnimal::makeSound() {
	std::cout << this->type << " makes some sound" << std::endl;
}