//
// Created by Diana catherine Salamanca leguizamon on 3/3/22.
//

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap() {
	_energyPoints = 50;
	std::cout << GREEN "ScavTrap " << _name
			  << " was created by default constructor." RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GREEN "ScavTrap " << _name
			  << " was created by name constructor." RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj) {
	std::cout << GREEN "ScavTrap " << _name
			  << " was created by copy constructor." RESET << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << RED ITALIC "ScavTrap " << _name << " was destroyed." RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj) {
	if (this != &obj) {
		_name = obj._name;
		_hitPoints = obj._hitPoints;
		_energyPoints = obj._energyPoints;
		_attackDamage = obj._attackDamage;
	}
	std::cout << GREEN "ScavTrap " << _name
			  << " was created by assignment operator." RESET << std::endl;
	return *this;
}

//overwrite original attack function
void ScavTrap::attack(const std::string &target) {
	if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << "ScavTrap " PURPLE << _name << RESET " attacks " PURPLE << target
				  << RESET ", causing " << _attackDamage
				  << " points of damage! \t" RESET;
		printScore(_hitPoints, _energyPoints);
	} else
		std::cout << ORANGE "ScavTrap doesn't have enough energy points to attack.\n" RESET << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " PURPLE << _name << ORANGE " is now in Gate keeper mode " RESET << std::endl;
}

// attack function overloaded
void ScavTrap::attack(ClapTrap &target) {
	attack(target.getName());
	target.takeDamage(_attackDamage);
}
