//
// Created by Diana Salamanca on 09-Mar-22.
//

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

Character::Character(const std::string &name) : _inventory(), _name(name) { //check ifis necessary init inventory
	for (int i = 0; i < MAX_SIZE; i++) {
		_inventory[i] = NULL;
	}
}

// Deep copy through clone
Character::Character(const Character &obj) : _inventory(), _name(obj._name) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (obj._inventory[i]) {
			_inventory[i] = obj._inventory[i]->clone();
		} else {
			_inventory[i] = NULL;
		}
	}
}

Character::~Character() {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
		}
	}
}

Character &Character::operator=(const Character &obj) {
	if (this != &obj) {
		_name = obj._name;
		for (int i = 0; i < MAX_SIZE; i++) {
			if (_inventory[i]) {
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (obj._inventory[i]) {
				_inventory[i] = obj._inventory[i]->clone();
			}
		}
	}
	return *this;
}

const std::string &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *materia) {
	if (!materia) {
		return;
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = materia;
			std::cout << "Materia " CYAN_L << _inventory[i]->getType()
					  << RESET " was equip in index " CYAN_L << i
					  << RESET " to " CYAN_L << _name << RESET << std::endl;
			return;
		}
		if (i == MAX_SIZE - 1 && _inventory[i] != NULL) {
			std::cout << ORANGE "Inventory equip is already full" RESET << std::endl;
			delete materia; //when inventory is full, to avoid memory leaks
			return;
		}
	}
}

// must NOT delete the Materia
void Character::unequip(int index) {
	if (index < 0 || index >= MAX_SIZE) {
		std::cout << ORANGE "Not possible to unequip an index out of range - slot[" << index
				  << "]" RESET << std::endl;
		return;
	}
	if (index >= 0 && index < MAX_SIZE && _inventory[index]) { //revisar
		std::cout << "Character " CYAN_L << _name << RESET " unequip " CYAN_L
				  << _inventory[index]->getType() << RESET " in index " CYAN_L
				  << index << RESET << std::endl;
		_inventory[index] = NULL;
	}
}

void Character::use(int index, ICharacter &target) {
	if (index >= 0 && index < MAX_SIZE && _inventory[index]) {
		_inventory[index]->use(target);
	} else if (index >= 0 && index < MAX_SIZE && _inventory[index] == NULL) {
		std::cout << ORANGE "No Materia found in index " << index << RESET << std::endl;
	} else
		std::cout << ORANGE "Not a valid index " << index << RESET << std::endl;
}

AMateria *Character::getInventory(unsigned int index) const {
	if (index >= MAX_SIZE)
		return NULL;
	return _inventory[index];
}

//Default constructor is not used in the main
Character::Character() {
}
