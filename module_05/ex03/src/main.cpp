//
// Created by Diana Salamanca on 11/03/2022.
//

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

static void printLine(const std::string &str) {
	std::cout << std::endl;
	std::cout << std::setfill('*') << std::setw(80) << "*" << std::setfill(' ') << std::endl;
	std::cout << std::setw(50) << std::right << str << std::endl;
	std::cout << std::setfill('*') << std::setw(80) << "*" << std::endl;
}

static void checkLeaks() {
	std::cout << ORANGE "\nChecking for leaks......" RESET << std::endl;
	system("leaks intern");
}

void runInternRobotomyTest() {
	try {
		Intern someRandomIntern;
		AForm *form;
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		delete form;
	} catch (Intern::NonExistenceFormException &e) {
		std::cout << e.what() << std::endl;
	}
}

void runInternShrubberyTest() {
	try {
		Intern someRandomIntern;
		AForm *form;
		form = someRandomIntern.makeForm("shrubbery creation", "Shu");
		delete form;
	} catch (Intern::NonExistenceFormException &e) {
		std::cout << e.what() << std::endl;
	}
}

void runInternPresidentialTest() {
	try {
		Intern someRandomIntern;
		AForm *form;
		form = someRandomIntern.makeForm("presidential pardon", "Presi");
		delete form;
	} catch (Intern::NonExistenceFormException &e) {
		std::cout << e.what() << std::endl;
	}
}

void runMixTest1() {
	try {
		Bureaucrat low("low", 30);
		std::cout << low << std::endl;
		Intern me;
		AForm *shrub;
		shrub = me.makeForm("shrubbery creation", "Bin");
		std::cout << shrub << std::endl;
		low.signForm(*shrub);
		low.executeForm(*shrub);
		std::cout << shrub << std::endl;
		delete shrub;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void runMixTest2() {
	try {
		Bureaucrat low("low", 50);
		std::cout << low << std::endl;
		Intern me;
		AForm *robot;
		robot = me.makeForm("robotomy request", "Bender");
		std::cout << robot << std::endl;
		low.signForm(*robot);
		low.executeForm(*robot);
		delete robot;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void runMixTest3() {
	try {
		Bureaucrat low("low", 30);
		std::cout << low << std::endl;
		Intern me;
		AForm *presi;
		presi = me.makeForm("presidential pardon", "Rigo");
		std::cout << presi << std::endl;
		low.signForm(*presi);
		low.executeForm(*presi);
		delete presi;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	std::srand(time(NULL)); // for Robotomy action
	printLine("Intern make Shrubbery Form Test");
	runInternShrubberyTest();
	printLine("Intern make Robotomy Form Test");
	runInternRobotomyTest();
	printLine("Intern make Presidential Form Test");
	runInternPresidentialTest();
	printLine("Mix Test 1");
	runMixTest1();
	printLine("Mix Test 2");
	runMixTest2();
	printLine("Mix Test 3");
	runMixTest3();
	checkLeaks();
	return 0;
}
