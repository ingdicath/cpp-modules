//
// Created by Diana catherine Salamanca leguizamon on 2/24/22.
//

# include "../includes/Fixed.hpp"
# include <iostream>
# include <cmath>

/**
 * Constructors and destructor.
 */
Fixed::Fixed() {
	this->_fixedPointNumber = 0;
}

Fixed::Fixed(const Fixed &obj) : _fixedPointNumber() {
	*this = obj;   // this calls to copy assignment operator
}

//Move x number of bits to represent a decimal number using an integer type.
Fixed::Fixed(const int intNumber) {
	this->_fixedPointNumber = intNumber << _numberFractionalBits;
}

// '1 << _numberFractionalBits' acts as a joker, it means to cast to new number system.
Fixed::Fixed(const float floatNumber) {
	float shifted = floatNumber * (1 << _numberFractionalBits); // casting float number to new number system
	float rounded = std::roundf(shifted); // round float number because new system accepts only integers
	this->_fixedPointNumber = static_cast<int>(rounded);
}

Fixed::~Fixed() {
}

/**
 * Overloaded comparison operators >, <, >=, <=, == and !=, also
 * overloaded assignment operator.
 * Left hand side and right hand side operands are immutable.
 */
Fixed &Fixed::operator=(const Fixed &obj) {
	if (this != &obj) {    // Self-assignment protection.
		this->_fixedPointNumber = obj.getRawBits();
	}
	return *this;
}

bool Fixed::operator>(const Fixed &obj) const {
	return (this->_fixedPointNumber > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const {
	return (this->_fixedPointNumber < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const {
	return (this->_fixedPointNumber >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const {
	return (this->_fixedPointNumber <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const {
	return (this->_fixedPointNumber == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const {
	return (this->_fixedPointNumber != obj.getRawBits());
}

/**
 * Overloaded arithmetic operators +, -, *, and /
 * Left hand side and right hand side operands are immutable.
 */
Fixed Fixed::operator+(const Fixed &obj) const {
	Fixed res;
	res.setRawBits(this->_fixedPointNumber + obj.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed &obj) const {
	Fixed res;
	res.setRawBits(this->_fixedPointNumber - obj.getRawBits());
	return res;
}

Fixed Fixed::operator*(const Fixed &obj) const {
	Fixed res;
	res.setRawBits((this->_fixedPointNumber * obj.getRawBits())
				   / (1 << _numberFractionalBits));
	return res;
}

Fixed Fixed::operator/(const Fixed &obj) const {
	Fixed res;
	res.setRawBits((this->_fixedPointNumber / obj.getRawBits())
				   * (1 << _numberFractionalBits));
	return res;
}

/**
 * Overloaded pre y post increment/ pre y post decrement operators.
 */
// Pre-increment overloading
Fixed &Fixed::operator++() {
	this->_fixedPointNumber += 1;
	return *this;
}

// Post-increment overloading
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->_fixedPointNumber += 1;
	return temp;
}

// Pre-decrement overloading
Fixed &Fixed::operator--() {
	this->_fixedPointNumber -= 1;
	return *this;
}

// Post-decrement overloading
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->_fixedPointNumber -= 1;
	return temp;
}

/**
 * Overloaded member functions min & max.
 */
Fixed &Fixed::min(Fixed &num1, Fixed &num2) {
	if (num1 > num2)
		return num2;
	return num1;
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2) {
	if (num1 > num2)
		return num2;
	return num1;
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2) {
	if (num1 > num2)
		return num1;
	return num2;
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2) {
	if (num1 > num2)
		return num1;
	return num2;
}

/**
 * Converter member functions.
 */
int Fixed::toInt() const {
	return this->_fixedPointNumber >> _numberFractionalBits;
}

float Fixed::toFloat() const {
	float casted = static_cast<float>(this->_fixedPointNumber);
	return casted / (1 << _numberFractionalBits);
}

/**
 * Getter and setter
 */
int Fixed::getRawBits() const {
	return this->_fixedPointNumber;
}

void Fixed::setRawBits(const int raw) {
	this->_fixedPointNumber = raw;
}

/**
 * Output streams use the insertion (<<) operator for standard types.
 * You can also overload the << operator for Fixed class.
 */
std::ostream &operator<<(std::ostream &out, const Fixed &obj) {
	return out << obj.toFloat();
}
