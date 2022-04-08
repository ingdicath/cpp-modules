//
// Created by Diana Salamanca on 07-Mar-22.
//

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << GREEN "Cat was created by default constructor." RESET << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj.getType()) {
	std::cout << GREEN "Cat was created by copy constructor." RESET << std::endl;
}

Cat::~Cat() {
	std::cout << RED ITALIC "Cat is gone." RESET << std::endl;
}

Cat &Cat::operator=(const Cat &obj) {
	if (this != &obj) {
		_type = obj._type;
	}
	std::cout << GREEN "Cat was created by assigment operator. " RESET << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << PURPLE "Miauu Miauu" << RESET << std::endl;
}
