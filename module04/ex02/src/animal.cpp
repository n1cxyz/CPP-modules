#include "animal.hpp"

AAnimal::AAnimal() {
	std::cout << "constructor called from Animal" << std::endl;
	this->type = "Animal";
};

AAnimal::AAnimal(const AAnimal &animal) {
	std::cout << "copy constructor called from Animal" << std::endl;
	*this = animal;
}

AAnimal& AAnimal::operator=(const AAnimal &animal) {
	std::cout << "assignment overload called from Animal" << std::endl;
	if (this == &animal) {
		return *this;
	}
	this->type = animal.type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "Destructor called from Animal" << std::endl;
};

/* void	AAnimal::makeSound() const {
	std::cout << this->type << " makes some sound" << std::endl;
}; */

std::string	AAnimal::getType() const {
	return this->type;
};

