//
// Created by Diana Salamanca on 07-Mar-22.
//

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal("Cat") {
	_brain = new Brain();
	std::cout << GREEN "Cat was created by default constructor." RESET << std::endl;
}

/**
 * In Deep copy, an object is created by copying data of all variables and
 * it also allocates similar memory resources with the same value to the object.
 * In order to perform Deep copy, we need to explicitly define the copy constructor
 * and assign dynamic memory as well if required.
 */
Cat::Cat(const Cat &obj) : AAnimal(obj.getType()) {
	_brain = new Brain(); // deep copy
	*_brain = *(obj._brain);
	std::cout << GREEN "Cat was created by copy constructor." RESET << std::endl;
}

Cat::~Cat() {
	delete _brain;
	std::cout << RED ITALIC "Cat is gone." RESET << std::endl;
}

/**
 * Because brain was created with assigment operator, is not needed to use delete.
 */
Cat &Cat::operator=(const Cat &obj) {
	if (this != &obj) {
		_type = obj._type;
		*_brain = *obj._brain;
	}
	std::cout << GREEN "Cat was created by assigment operator. " RESET << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << PURPLE "Miauu Miauu" << RESET << std::endl;
}

Brain *Cat::getBrain() const {
	return _brain;
}
