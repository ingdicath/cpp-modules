//
// Created by Diana Salamanca on 09-Mar-22.
//

#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure &obj) : AMateria(obj) {
}

Cure::~Cure() {
}

Cure &Cure::operator=(const Cure &) {
	return *this;
}

AMateria *Cure::clone() const {
	AMateria *clone = new Cure(*this); // constructor copy
	return clone;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " PURPLE << target.getName() << RESET "'s wounds *" << std::endl;
}
