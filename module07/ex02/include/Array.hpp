#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
private:
	T* 		_data;
	size_t	_size;

public:
	Array() : _data(NULL), _size(0) {}

	Array(size_t n) :_data(new T[n]), _size(n) {}

	Array(const Array& other) : _data(NULL), _size(other.size()) {
		if (_size > 0) {
			_data = new T[_size];
			for (size_t i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		}
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] _data;
			_size = other._size;
			_data = (_size > 0) ? new T[_size] : NULL;
			for (size_t i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		}
		return *this;
	}

	~Array() {
		delete[] _data;
	}

	T& operator[](size_t index) {
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _data[index];
	}

	const T& operator[](size_t index) const {
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _data[index];
	}

	size_t size() const {
		return _size;
	}
};
