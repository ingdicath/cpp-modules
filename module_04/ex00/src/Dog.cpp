//
// Created by Diana Salamanca on 06-Mar-22.
//

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << GREEN "Dog was created by default constructor." RESET << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj.getType()) {
	std::cout << GREEN "Dog was created by copy constructor." RESET << std::endl;
}

Dog::~Dog() {
	std::cout << RED ITALIC "Dog is gone." RESET << std::endl;
}

Dog &Dog::operator=(const Dog &obj) {
	if (this != &obj) {
		_type = obj._type;
	}
	std::cout << GREEN "Dog was created by assigment operator. " RESET << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << PURPLE "Woof Woof" << RESET << std::endl;
}
