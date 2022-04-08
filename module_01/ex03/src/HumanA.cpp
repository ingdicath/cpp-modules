//
// Created by Diana catherine Salamanca leguizamon on 2/10/22.
//

#include "../includes/HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) {
	this->_name = name;
	this->_weapon = &weapon;
}

HumanA::~HumanA() {
}

void HumanA::attack() {
	std::cout << CYAN << _name << RESET << " attacks with their "
			  << CYAN << _weapon->getType() << RESET << std::endl;
}
