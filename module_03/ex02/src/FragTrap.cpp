//
// Created by Diana Salamanca on 03/03/2022.
//

#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << GREEN "FragTrap " << _name
			  << " was created by name constructor." RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj) {
	std::cout << GREEN "FragTrap " << _name
			  << " was created by copy constructor." RESET << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << RED ITALIC "FragTrap " << _name << " was destroyed." RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj) {
	if (this != &obj) {
		_name = obj._name;
		_hitPoints = obj._hitPoints;
		_energyPoints = obj._energyPoints;
		_attackDamage = obj._attackDamage;
	}
	std::cout << GREEN "FragTrap " << _name
			  << " was created by assignment operator." RESET << std::endl;
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " PURPLE << _name << ORANGE " wants to give a high fives!" RESET << std::endl;
}

// Default constructor implementation, is not used in the main.
FragTrap::FragTrap() {
}
