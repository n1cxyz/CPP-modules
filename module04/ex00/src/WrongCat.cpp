#include "WrongCat.hpp"


WrongCat::WrongCat() {
	std::cout << "constructor called from WrongCat" << std::endl;
	this->type = "WrongCat";
};

WrongCat::WrongCat(const WrongCat &WrongCat) : WrongAnimal(WrongCat) {
	std::cout << "copy constructor called from WrongCat" << std::endl;
	this->type = WrongCat.type;
};

WrongCat& WrongCat::operator=(const WrongCat &WrongCat) {
	std::cout << "assignment overload called from WrongCat" << std::endl;
	if (this == &WrongCat) {
		return *this;
	}
	this->type = WrongCat.type;
	return *this;
};

WrongCat::~WrongCat() {
	std::cout << "Destructor called from WrongCat" << std::endl;
};

void	WrongCat::makeSound() {
	std::cout << this->type << ": meow" << std::endl;
};