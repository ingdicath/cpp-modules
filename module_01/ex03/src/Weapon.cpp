//
// Created by Diana catherine Salamanca leguizamon on 2/10/22.
//

#include "../includes/Weapon.hpp"

Weapon::Weapon(const std::string &type) {
	_type = type;
}

Weapon::~Weapon() {
}

const std::string &Weapon::getType() const {
	return _type;
}

void Weapon::setType(const std::string &type) {
	_type = type;
}
