#include "animal.hpp"

Animal::Animal() {
	std::cout << "constructor called from Animal" << std::endl;
	this->type = "Animal";
};

Animal::Animal(const Animal &animal) {
	std::cout << "copy constructor called from Animal" << std::endl;
	this->type = animal.type;
}

Animal& Animal::operator=(const Animal &animal) {
	std::cout << "assignment overload overload called from Animal" << std::endl;
	if (this == &animal) {
		return *this;
	}
	this->type = animal.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Destructor called from Animal" << std::endl;
};

void	Animal::makeSound() {
	std::cout << this->type << " makes some sound" << std::endl;
}
