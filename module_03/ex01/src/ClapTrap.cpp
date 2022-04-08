//
// Created by Diana Salamanca on 03/03/2022.
//

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

void ClapTrap::printScore(int a, int b) {
	std::cout << CYAN_L "HP.: " << a
			  << ", EP.: " << b
			  << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10),
											  _energyPoints(10), _attackDamage(0) {
	std::cout << GREEN "ClapTrap " << _name
			  << " was created by name constructor." RESET << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << RED ITALIC "ClapTrap " << _name << " was destroyed." RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) : _name(obj._name), _hitPoints(obj._hitPoints),
										  _energyPoints(obj._energyPoints),
										  _attackDamage(obj._attackDamage) {
	std::cout << GREEN "ClapTrap " << _name
			  << " was created by copy constructor." RESET << std::endl;
	*this = obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj) {
	if (this != &obj) {
		_name = obj._name;
		_hitPoints = obj._hitPoints;
		_energyPoints = obj._energyPoints;
		_attackDamage = obj._attackDamage;
	}
	std::cout << GREEN "ClapTrap " << _name
			  << " was created by assignment operator." RESET << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << "ClapTrap " PURPLE << _name << RESET " attacks " PURPLE << target
				  << RESET ", causing " << _attackDamage
				  << " points of damage! \t" RESET;
		printScore(_hitPoints, _energyPoints);
	} else
		std::cout << ORANGE "ClapTrap doesn't have enough energy points to attack.\n" RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	_hitPoints -= static_cast<int>(amount);
	if (_hitPoints <= 0) {
		std::cout << SALMON ITALIC "ClapTrap " << _name << " got killed.\n" RESET << std::endl;
	} else {
		std::cout << "ClapTrap " PURPLE << _name << RESET " took " << amount
				  << " points of damage. \t\t\t" RESET;
		printScore(_hitPoints, _energyPoints);
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	_hitPoints += static_cast<int>(amount);
	if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << "ClapTrap " PURPLE << _name << RESET " got "
				  << amount << " hit points back. \t\t\t\t" RESET;
		printScore(_hitPoints, _energyPoints);
	} else
		std::cout << ORANGE "There are not enough energy points to be repaired." RESET << std::endl;
}

const std::string &ClapTrap::getName() const {
	return _name;
}

// Default constructor implementation, is not used in the main.
ClapTrap::ClapTrap() {
}
