//
// Created by Diana Salamanca on 19/02/2022.
//

#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() {
	std::cout << PURPLE "Default constructor called" RESET << std::endl;
	this->_fixedPointNumber = 0;
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << PURPLE "Copy constructor called" RESET << std::endl;
	*this = obj;   // this calls to copy assignment operator
}

Fixed &Fixed::operator=(const Fixed &obj) {
	std::cout << PURPLE "Copy assignment operator called " RESET << std::endl;
	if (this != &obj) {   // Self-assignment protection.
		this->_fixedPointNumber = obj.getRawBits();
	}
	return *this;
}

/**
 * Move x number of bits to represent a decimal number using an integer type.
 */
Fixed::Fixed(const int intNumber) {
	std::cout << PURPLE "Int constructor called" RESET << std::endl;
	this->_fixedPointNumber = intNumber << _numberFractionalBits;
}

/**
 * '1 << _numberFractionalBits' acts as a joker, it means to cast to new
 * number system.
 */
Fixed::Fixed(const float floatNumber) {
	std::cout << PURPLE "Float constructor called" RESET << std::endl;
	float shifted =
			floatNumber * (1 << _numberFractionalBits);  // casting float number to new number system
	float rounded = std::roundf(
			shifted);  // round float number because new system accepts only integers
	this->_fixedPointNumber = static_cast<int>(rounded);
}

Fixed::~Fixed() {
	std::cout << RED "Destructor called" RESET << std::endl;
}

int Fixed::toInt() const {
	return this->_fixedPointNumber >> _numberFractionalBits;
}

float Fixed::toFloat() const {
	float casted = static_cast<float>(this->_fixedPointNumber);
	return casted / (1 << _numberFractionalBits);
}

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
