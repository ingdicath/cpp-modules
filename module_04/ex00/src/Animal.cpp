//
// Created by Diana Salamanca on 06-Mar-22.
//

#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal() {
	std::cout << GREEN "Animal was created by default constructor." RESET << std::endl;
}

Animal::Animal(const std::string &type) : _type(type) {
	std::cout << GREEN "Animal was created by type constructor." RESET << std::endl;
}

Animal::Animal(const Animal &obj) : _type(obj._type) {
	std::cout << GREEN "Animal was created by copy constructor." RESET << std::endl;
}

Animal::~Animal() {
	std::cout << RED ITALIC "Animal is gone." RESET << std::endl;
}

Animal &Animal::operator=(const Animal &obj) {
	if (this != &obj) {
		_type = obj._type;
	}
	std::cout << GREEN "Animal was created by assigment operator. " RESET << std::endl;
	return *this;
}

void Animal::makeSound() const {
	std::cout << PURPLE "~ Generic sound ~ " << RESET << std::endl;
}

const std::string &Animal::getType() const {
	return _type;
}
