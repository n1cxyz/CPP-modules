#include "../include/Fixed.hpp"

Fixed::Fixed() {
	//std::cout << "Default constructor called" << "\n";
	this->rawBits = 0;
}

Fixed::Fixed(const int number) {
	//std::cout << "Int constructor called" << "\n";
	this->rawBits = number << this->fractionalBits;
}

Fixed::Fixed(const float floatNumber) {
	//std::cout << "Float constructor called" << "\n";
	this->rawBits = (int)(roundf(floatNumber * (1 << this->fractionalBits)));
}

Fixed::Fixed(const Fixed& fixed) {
	//std::cout << "Copy constructor called" << "\n";
	this->rawBits = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &fixed) {
	if (this == &fixed) {
		return *this;
	}
	//std::cout << "Copy assignment operator called" << "\n";
	this->rawBits = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << "\n";
}

bool Fixed::operator>(const Fixed& other) const { 
	return getRawBits() > other.getRawBits(); }

bool Fixed::operator<(const Fixed& other) const {
    return getRawBits() < other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return getRawBits() <= other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return getRawBits() >= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &obj) const {

    return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed &obj) const {

    return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed	result;

	result.setRawBits((this->getRawBits() * other.getRawBits()) >> Fixed::fractionalBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const {
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed&	Fixed::operator++(void) {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);

	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed&	Fixed::operator--(void) {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed temp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return temp;
}

int	Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << "\n";
	return this->rawBits;
}

void	Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits member function called" << "\n";
	this->rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return (float)(this->rawBits) / (1 << fractionalBits);
}

int		Fixed::toInt(void) const {
	return (int)(this->rawBits >> this->fractionalBits);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }

std::ostream& operator<<(std::ostream &output, const Fixed &a) {
	output << a.toFloat();
	return output;
}