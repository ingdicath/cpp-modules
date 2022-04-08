//
// Created by Diana Salamanca on 11/03/2022.
//

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>

static void printLine(const std::string &str) {
	std::cout << std::endl;
	std::cout << std::setfill('*') << std::setw(50) << "*" << std::setfill(' ') << std::endl;
	std::cout << std::setw(30) << std::right << str << std::endl;
	std::cout << std::setfill('*') << std::setw(50) << "*" << std::endl;
}

void runRangeLimitsTest() {
	try {
		Bureaucrat me("Me", MAX_GRADE);
		me.incrementGrade();
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	try {
		Bureaucrat you("You", MIN_GRADE);
		you.decrementGrade();
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
}

void runOutofRangeTest() {
	try {
		Bureaucrat pepito("Pepito", MAX_GRADE - 1);
		pepito.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	try {
		Bureaucrat perez("Perez", MIN_GRADE + 1);
		perez.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
}

void runNormalRangeTest() {
	try {
		Bureaucrat grogu("Grogu", 2);
		grogu.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat grogu("Grogu", 2);
		grogu.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat nieve("Nieve", 149);
		nieve.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat nieve("Nieve", 149);
		nieve.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
}

void runDefaultTest() {
	try {
		Bureaucrat grogu("Grogu", 120);
		std::cout << grogu << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	printLine("Range Limits");
	runRangeLimitsTest();
	printLine("Out of Limits");
	runOutofRangeTest();
	printLine("Inside Limits");
	runNormalRangeTest();
	printLine("Default");
	runDefaultTest();
	return 0;
}
