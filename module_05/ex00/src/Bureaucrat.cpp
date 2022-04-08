//
// Created by Diana Salamanca on 11/03/2022.
//

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

Bureaucrat::Bureaucrat(const std::string &name, short grade) : _name(name), _grade(grade) {
	if (grade > MIN_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
	if (grade < MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}
	std::cout << GREEN "Bureaucrat '" << _name
			  << "' was created." RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _grade() {
	*this = obj;
	std::cout << GREEN "Bureaucrat '" << _name
			  << "' was created by copy constructor." RESET << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << RED ITALIC "Bureaucrat '" << _name << "' was destroyed." RESET << std::endl;
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
	if (this != &obj) {
		_grade = obj._grade;
	}
	std::cout << GREEN "Bureaucrat '" << _name
			  << "' was created by assigment operator." RESET << std::endl;
	return *this;
}


/**
 * Grade has ranges from 1 (highest possible grade) to 150 (lowest possible
 * grade).
 */
void Bureaucrat::incrementGrade() {
	if (_grade <= MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
	std::cout << CYAN_L << _name
			  << "'s grade was increased. New value: " << _grade << RESET << std::endl;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= MIN_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
	std::cout << CYAN_L << _name
			  << "'s grade was decreased. New value: " << _grade << RESET << std::endl;
}


const std::string &Bureaucrat::getName() const {
	return _name;
}

unsigned int Bureaucrat::getGrade() const {
	return _grade;
}


const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ORANGE "Bureaucrat grade is too high. Values must be between 1 and 150." RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ORANGE "Bureaucrat grade is too low. Values must be between 1 and 150." RESET;
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << "name: " PURPLE << bureaucrat.getName()
	   << RESET ", bureaucrat grade: " PURPLE << bureaucrat.getGrade() << RESET;
	return os;
}

// Default constructor not used in main
Bureaucrat::Bureaucrat() : _grade() {
}
