//
// Created by Diana Salamanca on 16/03/2022.
//

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
		: AForm("Robotomy Form", 72, 45) {
	setTarget(target);
	std::cout << GREEN "Robotomy '" << getTarget() << "' was created." RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
		: AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExecute()) {
	setTarget(obj.getTarget());
	std::cout << GREEN "Robotomy '" << getTarget()
			  << "' was created by copy constructor." RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << RED ITALIC "'" << getTarget() << "' was destroyed." RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	if (this != &obj) {
		setTarget(obj.getTarget());
	}
	std::cout << GREEN "Robotomy '" << getTarget()
			  << "' was created by assignment operator." RESET << std::endl;
	return *this;
}


void RobotomyRequestForm::action() const {
	std::cout << PURPLE "*** drilling noises Rrr Rrr Rrr Rrr ***" RESET << std::endl;
	if (std::rand() % 2) {
		std::cout << PURPLE << getTarget()
				  << RESET " has been robotomized successfully." RESET << std::endl;
	} else {
		std::cout << ORANGE "The robotomy failed." RESET << std::endl;
	}
}

// Default constructor not used in main
RobotomyRequestForm::RobotomyRequestForm() {
}
