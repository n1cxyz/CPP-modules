#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

class Serializer {
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);

	typedef struct Data {

	};
public:
	uintptr_t	serialize(Data* ptr);
	Data* 		deserialize(uintptr_t raw);
};

#endif