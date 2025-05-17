#include "animal.hpp"
#include "cat.hpp"
#include "dog.hpp"
#include "brain.hpp"

int	main(void) {

	//AAnimal animal;
	//animal.makeSound();
	Dog	d;
	AAnimal*	a = &d;
	a->makeSound();

	return 0;
};