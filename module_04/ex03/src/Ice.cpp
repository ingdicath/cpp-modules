//
// Created by Diana catherine Salamanca leguizamon on 3/9/22.
//

#include "Ice.hpp"
#include "AMateria.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice &obj) : AMateria(obj) {
}

Ice::~Ice() {
}

Ice &Ice::operator=(const Ice &) {
	return *this;
}

AMateria *Ice::clone() const {
	AMateria *clone = new Ice(*this); // constructor copy
	return clone;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " PURPLE << target.getName()
			  << RESET " *" << std::endl;
}
