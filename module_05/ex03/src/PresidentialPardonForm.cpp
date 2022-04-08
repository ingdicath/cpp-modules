//
// Created by Diani on 16/03/2022.
//

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp" //colors
#include <iostream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
		: AForm("Presidential Form", 25, 5) {
	setTarget(target);
	std::cout << GREEN "Presidential '" << getTarget() << "' was created." RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
		: AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExecute()) {
	setTarget(obj.getTarget());
	std::cout << GREEN "Presidential '" << getTarget()
			  << "' was created by copy constructor." RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << RED ITALIC "'" << getTarget() << "' was destroyed." RESET << std::endl;
}


PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
	if (this != &obj) {
		setTarget(obj.getTarget());
	}
	std::cout << GREEN "Presidential '" << getTarget()
			  << "' was created by assignment operator." RESET << std::endl;
	return *this;
}


void PresidentialPardonForm::action() const {
	std::cout << PURPLE "'" << getTarget()
			  << "' has been pardoned by Zaphod Beeblebrox" RESET << std::endl;
}

// Default constructor not used in main
PresidentialPardonForm::PresidentialPardonForm() {
}
