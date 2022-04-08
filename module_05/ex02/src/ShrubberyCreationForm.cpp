//
// Created by Diana Salamanca on 16/03/2022.
//

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
		: AForm("Shrubbery Form", 145, 137) {
	setTarget(target);
	std::cout << GREEN "Shrubbery '" << getTarget() << "' was created." RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
		: AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExecute()) {
	setTarget(obj.getTarget());
	std::cout << GREEN "Shrubbery '" << getTarget()
			  << "' was created by copy constructor." RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << RED ITALIC "'" << getTarget() << "' was destroyed." RESET << std::endl;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
	if (this != &obj) {
		setTarget(obj.getTarget());
	}
	std::cout << GREEN "Shrubbery '" << getTarget()
			  << "' was created by assignment operator." RESET << std::endl;
	return *this;
}


// You only need to convert it to a c-string if you are not using c++11 or later.
void ShrubberyCreationForm::action() const {
	std::ofstream myFile;
	std::string nameFile = getTarget() + "_shrubbery";
	myFile.open(nameFile.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!myFile.is_open()) {
		throw std::runtime_error("Could not open file");
	}
	myFile << "      _-_\n"
		   << "   /~~   ~~\\\n"
		   << " /~~       ~~\\\n"
		   << "{             }\n"
		   << "\\  _-    -_  /\n"
		   << "  ~  \\\\ //  ~\n"
		   << "_- -  | | _- _\n"
		   << "_ -   | |   -_\n"
		   << "     // \\\\";
	myFile.close();
}


// Default constructor not used in main
ShrubberyCreationForm::ShrubberyCreationForm() {
}
