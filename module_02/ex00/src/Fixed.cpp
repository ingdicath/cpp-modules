//
// Created by Diani on 18/02/2022.
//

#include "../includes/Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
	std::cout << PURPLE << "Default constructor called" << RESET << std::endl;
	this->_fixedPointNumber = 0;
}

/**
 * A copy constructor is a member function that initializes an object
 * using another object of the same class.
 */
Fixed::Fixed(const Fixed &obj) {
	std::cout << PURPLE "Copy constructor called" << RESET << std::endl;
	*this = obj;    // this calls to copy assignment operator
}

/**
 * The assignment operator for a class is what allows you to use
 * '=' to assign one instance to another.
 */
Fixed &Fixed::operator=(const Fixed &obj) {
	std::cout << PURPLE "Copy assignment operator called " << RESET << std::endl;
	if (this != &obj) {    // Self-assignment protection.
		this->_fixedPointNumber = obj.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointNumber;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointNumber = raw;
}
