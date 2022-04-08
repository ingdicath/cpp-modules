//
// Created by Diana Salamanca on 06-Mar-22.
//

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	_brain = new Brain();
	std::cout << GREEN "Dog was created by default constructor." RESET << std::endl;
}

/**
 * In Deep copy, an object is created by copying data of all variables and
 * it also allocates similar memory resources with the same value to the object.
 * In order to perform Deep copy, we need to explicitly define the copy constructor
 * and assign dynamic memory as well if required.
 */
Dog::Dog(const Dog &obj) : Animal(obj.getType()) {
	_brain = new Brain(); // deep copy
	*_brain = *obj._brain;
	std::cout << GREEN "Dog was created by copy constructor." RESET << std::endl;
}

Dog::~Dog() {
	delete _brain;
	std::cout << RED ITALIC "Dog is gone." RESET << std::endl;
}

/**
 * Because brain was created with assigment operator, is not needed to use delete.
 */
Dog &Dog::operator=(const Dog &obj) {
	if (this != &obj) {
		_type = obj._type;
		*_brain = *obj._brain;
	}
	std::cout << GREEN "Dog was created by assigment operator. " RESET << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << PURPLE "Woof Woof" << RESET << std::endl;
}

Brain *Dog::getBrain() const {
	return _brain;
}

// With a shallow copy, you copy the pointer itself. As a result,
// both the original and the copy will point to the same data.
// With a deep copy, you make a copy of the pointed-at data and change the pointer.
// So the original and the copy point to distinct data.
