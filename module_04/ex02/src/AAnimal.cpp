//
// Created by Diana Salamanca on 06-Mar-22.
//

#include "AAnimal.hpp"
#include <iostream>
#include <string>

AAnimal::AAnimal() {
	std::cout << GREEN "AAnimal was created by default constructor." RESET << std::endl;
}

AAnimal::AAnimal(const std::string &type) : _type(type) {
	std::cout << GREEN "AAnimal was created by type constructor." RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj) : _type(obj._type) {
	std::cout << GREEN "AAnimal was created by copy constructor." RESET << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << RED ITALIC "AAnimal is gone." RESET << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &obj) {
	if (this != &obj) {
		_type = obj._type;
	}
	std::cout << GREEN "AAnimal was created by assigment operator. " RESET << std::endl;
	return *this;
}

const std::string &AAnimal::getType() const {
	return _type;
}
