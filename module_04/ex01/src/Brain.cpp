//
// Created by Diana Salamanca on 07/03/2022.
//

#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain() {
	std::cout << GREEN "Brain created by default constructor." RESET << std::endl;
}

Brain::Brain(const Brain &obj) {
	std::cout << GREEN "Brain was created by copy constructor." RESET << std::endl;
	*this = obj;
}

Brain::~Brain() {
	std::cout << RED ITALIC "Brain was destructed." RESET << std::endl;
}

Brain &Brain::operator=(const Brain &obj) {
	if (this != &obj) {
		for (int i = 0; i < NUM_IDEAS; i++) {
			_ideas[i] = obj._ideas[i];
		}
	}
	std::cout << GREEN "Brain was created by assigment operator. " RESET << std::endl;
	return *this;
}

const std::string *Brain::getIdeas() const {
	return _ideas;
}

void Brain::setIdea(unsigned int pos, const std::string &idea) {
	if (pos > NUM_IDEAS) {
		return;
	}
	_ideas[pos] = idea;
}
