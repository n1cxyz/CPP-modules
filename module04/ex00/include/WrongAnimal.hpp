#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &WrongAnimal);
		~WrongAnimal();
		WrongAnimal& operator = (const WrongAnimal &WrongAnimal);

		void makeSound(void);
	protected:
		std::string type;
};

#endif