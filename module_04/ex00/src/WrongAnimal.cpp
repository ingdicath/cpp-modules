//
// Created by Diana Salamanca on 07-Mar-22.
//

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() {
	std::cout << GREEN "Wrong Animal was created by default constructor." RESET << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
	std::cout << GREEN "Wrong Animal was created by type constructor." RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED ITALIC "Wrong Animal is gone." RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) : _type(obj._type) {
	std::cout << GREEN "Wrong Animal was created by copy constructor." RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) {
	if (this != &obj) {
		_type = obj._type;
	}
	std::cout << GREEN "Animal was created by assigment operator. " RESET << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << PURPLE "~ Wrong Generic sound ~ " << RESET << std::endl;
}

const std::string &WrongAnimal::getType() const {
	return _type;
}
