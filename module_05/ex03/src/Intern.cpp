//
// Created by Diana Salamanca on 16/03/2022.
//

#include "Intern.hpp"
#include "Bureaucrat.hpp" //colors
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <iostream>
#include <string>

Intern::Intern() {
	std::cout << GREEN "Intern was created." RESET << std::endl;
}

Intern::Intern(const Intern &obj) {
	*this = obj;
	std::cout << GREEN "Intern was created by copy constructor." RESET << std::endl;
}

Intern::~Intern() {
	std::cout << RED ITALIC "Intern was destroyed." RESET << std::endl;
}


Intern &Intern::operator=(const Intern &obj) {
	if (this != &obj) {
		(void) obj;
	}
	std::cout << GREEN "Intern was created by assigment operator." RESET << std::endl;
	return *this;
}


// Mapping the strings to enum values(integers), allows using them in switch case.
int Intern::resolveType(const std::string &formName) {
	std::string formType[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int res = 4;
	for (int i = 0; i < res; i++) {
		if (formName == formType[i]) {
			res = i;
			break;
		}
	}
	return res;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
	AForm *newForm;
	switch (resolveType(formName)) {
		case SHRUBBERY:
			newForm = new ShrubberyCreationForm(target);
			break;
		case ROBOTOMY:
			newForm = new RobotomyRequestForm(target);
			break;
		case PRESIDENTIAL:
			newForm = new PresidentialPardonForm(target);
			break;
		default:
			throw NonExistenceFormException();
	}
	std::cout << "Intern creates " PURPLE << formName << RESET << std::endl;
	return newForm;
}


const char *Intern::NonExistenceFormException::what() const throw() {
	return ORANGE "Form doesn't exist." RESET;
}
