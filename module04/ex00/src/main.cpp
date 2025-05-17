#include "animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "cat.hpp"
#include "dog.hpp"

void	doSound(Animal* animal) {
	animal->makeSound();
}

void	doWrongSound(WrongAnimal* animal) {
	animal->makeSound();
}

int	main(void) {

	Dog dog;
	Cat cat;
	WrongCat wrongCat;
	
	doSound(&cat);
	doSound(&dog);
	doWrongSound(&wrongCat);
}