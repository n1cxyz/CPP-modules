#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << "\n";
	this->rawBits = 0;
}

Fixed::Fixed(const int number) {
	std::cout << "Int constructor called" << "\n";
	this->rawBits = number << this->fractionalBits;
}

Fixed::Fixed(const float floatNumber) {
	std::cout << "Float constructor called" << "\n";
	this->rawBits = (int)(roundf(floatNumber * (1 << this->fractionalBits)));
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << "\n";
	this->rawBits = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &fixed) {
	if (this == &fixed) {
		return *this;
	}
	std::cout << "Copy assignment operator called" << "\n";
	this->rawBits = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << "\n";
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << "\n";
	return this->rawBits;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << "\n";
	this->rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return (float)(this->rawBits) / (1 << fractionalBits);
}

int		Fixed::toInt(void) const {
	return (int)(this->rawBits >> this->fractionalBits);
}

std::ostream& operator<<(std::ostream &output, const Fixed &a) {
	output << a.toFloat();
	return output;
}