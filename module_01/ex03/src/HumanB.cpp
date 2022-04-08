//
// Created by Diana catherine Salamanca leguizamon on 2/10/22.
//

#include "../includes/HumanB.hpp"

HumanB::HumanB(const std::string &name) {
	this->_name = name;
}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void HumanB::attack() {
	std::cout << PURPLE << this->_name << RESET << " attacks with their "
			  << PURPLE << this->_weapon->getType() << RESET << std::endl;
}
