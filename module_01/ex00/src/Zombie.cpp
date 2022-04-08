//
// Created by Diana Salamanca on 09/02/2022.
//

#include "../includes/Zombie.hpp"

Zombie::Zombie() {
}

Zombie::~Zombie() {
	std::cout << RED << this->_name << " has been destroyed." << RESET << std::endl;
}

void Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/**
 * The parameter 'name' is copied for each invocation but only
 * is used as a const reference;
 */

void Zombie::setName(const std::string &name) {
	this->_name = name;
}
