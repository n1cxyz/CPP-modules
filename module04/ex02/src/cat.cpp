#include "cat.hpp"

Cat::Cat() {
	std::cout << "constructor called from Cat" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
};

Cat::Cat(const Cat &cat) : AAnimal(cat) {
	std::cout << "copy constructor called from Cat" << std::endl;
	this->brain = new Brain(*cat.brain);
};

Cat& Cat::operator=(const Cat &cat) {
	std::cout << "assignment overload called from Cat" << std::endl;
	if (this == &cat) {
		return *this;
	}
	AAnimal::operator=(cat);
	delete this->brain;
	this->brain = new Brain(*cat.brain);
	return *this;
};

Cat::~Cat() {
	std::cout << "Destructor called from Cat" << std::endl;
	delete this->brain;
};

void	Cat::makeSound() const {
	std::cout << this->type << ": meow" << std::endl;
};