//
// Created by Diana Salamanca on 09-Mar-22.
//

#include "AMateria.hpp"
#include "Character.hpp"
#include <iostream>

AMateria::AMateria() : _type("") {
}

AMateria::AMateria(const std::string &type) : _type(type) {
}

AMateria::AMateria(const AMateria &obj) : _type(obj._type) {
}

AMateria::~AMateria() {
}

AMateria &AMateria::operator=(const AMateria &) {
	return *this;
}

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	std::cout << "Type " << _type << " is against " << target.getName() << std::endl;
}
