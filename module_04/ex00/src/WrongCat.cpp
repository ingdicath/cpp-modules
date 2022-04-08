//
// Created by Diana Salamanca on 07-Mar-22.
//

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << GREEN "Wrong Cat was created by default constructor." RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj.getType()) {
	std::cout << GREEN "Wrong Cat was created by copy constructor." RESET << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << RED ITALIC "Wrong Cat is gone." RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj) {
	if (this != &obj) {
		_type = obj._type;
	}
	std::cout << GREEN "Wrong Cat was created by assigment operator. " RESET << std::endl;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << PURPLE "Wrong Miauu Miauu" << RESET << std::endl;
}
