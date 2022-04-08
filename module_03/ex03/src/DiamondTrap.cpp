//
// Created by Diani on 04/03/2022.
//

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(const std::string &name)
		: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) {
	std::cout << GREEN "DiamondTrap " << _name
			  << " was created by name constructor." RESET << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << RED ITALIC "DiamondTrap " << _name << " was destroyed." RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj) {
	*this = obj;
	std::cout << GREEN "DiamondTrap " << _name
			  << " was created by copy constructor." RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj) {
	if (this != &obj) {
		ClapTrap::_name = obj.ClapTrap::_name;
		_name = obj._name;
		_hitPoints = obj._hitPoints;
		_energyPoints = obj._energyPoints;
		_attackDamage = obj._attackDamage;
	}
	std::cout << GREEN "DiamondTrap " << _name
			  << " was created by assignment operator." RESET << std::endl;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap is " PURPLE << _name << RESET " and Claptrap is " PURPLE
			  << ClapTrap::_name << RESET << std::endl;
}

// Default constructor implementation, is not used in the main.
DiamondTrap::DiamondTrap() {
}
