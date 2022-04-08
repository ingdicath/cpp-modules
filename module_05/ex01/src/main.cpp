//
// Created by Diana Salamanca on 11/03/2022.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>

static void printLine(const std::string &str) {
	std::cout << std::endl;
	std::cout << std::setfill('*') << std::setw(50) << "*" << std::setfill(' ') << std::endl;
	std::cout << std::setw(30) << std::right << str << std::endl;
	std::cout << std::setfill('*') << std::setw(50) << "*" << std::endl;
}

void runFormCreationTest() {
	std::cout << "~~~ Out of range in Form - grade sign ~~~" << std::endl;
	try {
		Form complain("complain", 0, 42);
	} catch (Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form complain("complain", 151, 42);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "~~~ Out of range in Form - grade execute ~~~" << std::endl;
	try {
		Form complain("complain", 42, 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form complain("complain", 42, 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "~~~ In range values in Form ~~~" << std::endl;
	try {
		Form complain("complain", 42, 150);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void runSignedTest() {
	std::cout << "~~~ Bureaucrat grade is lower vs. grade required to sign ~~~" << std::endl;
	std::cout << "CASE 1" << std::endl;
	try {
		Bureaucrat grogu("Grogu", 11);
		Form complain("complain", 10, 149);
		std::cout << grogu << std::endl;
		std::cout << complain << std::endl;
		complain.beSigned(grogu);
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "CASE 2" << std::endl;
	try {
		Bureaucrat grogu("Grogu", 11);
		Form complain("complain", 10, 149);
		std::cout << grogu << std::endl;
		std::cout << complain << std::endl;
		grogu.signForm(complain);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "~~~ Bureaucrat grade high vs. grade required to sign ~~~" << std::endl;
	try {
		Bureaucrat grogu("Grogu", 9);
		Form complain("complain", 10, 149);
		std::cout << grogu << std::endl;
		std::cout << complain << std::endl;
		complain.beSigned(grogu);
		std::cout << complain << std::endl; //shows signed true
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "~~~ Bureaucrat grade equal to grade required to sign ~~~" << std::endl;
	try {
		Bureaucrat grogu("Grogu", 10);
		Form complain("complain", 10, 149);
		std::cout << grogu << std::endl;
		std::cout << complain << std::endl;
		grogu.signForm(complain);
		std::cout << complain << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void runMixTest() {
	try {
		Bureaucrat grogu("grogu", 42);
		Form e01("e01", 42, 84);
		Form e14("e14", 41, 10);

		std::cout << grogu << std::endl;
		std::cout << e01 << std::endl;
		std::cout << e14 << std::endl;
		grogu.signForm(e01);
		grogu.signForm(e14);
		std::cout << e01 << std::endl;
		std::cout << e14 << std::endl << std::endl;

		grogu.incrementGrade();
		grogu.signForm(e14);
		std::cout << grogu << std::endl;
		std::cout << e01 << std::endl;
		std::cout << e14 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	printLine("Form creation tests");
	runFormCreationTest();
	printLine("Signed tests");
	runSignedTest();
	printLine("Mix tests");
	runMixTest();
	return 0;
}
