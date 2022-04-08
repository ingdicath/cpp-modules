//
// Created by Diana Salamanca on 10-Mar-22.
//

#include "MateriaSource.hpp"
#include <iostream>
#include <string>

MateriaSource::MateriaSource() : _inventory() {
	for (int i = 0; i < MAX_SIZE; ++i) {
		_inventory[i] = NULL;
	}
}

// deep copy through clone
MateriaSource::MateriaSource(const MateriaSource &obj) : _inventory() {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (obj._inventory[i]) {
			_inventory[i] = obj._inventory[i]->clone();
		} else {
			_inventory[i] = NULL;
		}
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MAX_SIZE; ++i) {
		delete _inventory[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj) {
	if (this != &obj) {
		for (int i = 0; i < MAX_SIZE; i++) {
			if (_inventory[i]) {
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (obj._inventory[i]) {
				_inventory[i] = obj._inventory[i]->clone();
			} else {
				_inventory[i] = NULL;
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (!materia) {
		return;
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = materia;
			return;
		}
		if (_inventory[MAX_SIZE - 1] != NULL) {
			std::cout << ORANGE "Inventory learn is already full" RESET << std::endl;
			delete materia; //when inventory is full, to avoid memory leaks
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (_inventory[i] && (type == _inventory[i]->getType())) {
			return _inventory[i]->clone();
		}
	}
	std::cout << ORANGE "Type '" << type << "' is unknown." RESET << std::endl;
	return 0;
}
