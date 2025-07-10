#pragma once

#include <cstddef>
#include <stdexcept>
#include <new>

template <typename T>
class Array {
private:
	*T 			_data;
	size_t	_size;
public:
	Array() : _data(NULL), _size 
};
