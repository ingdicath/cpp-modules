//
// Created by Diana Salamanca on 11/03/2022.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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

static void printSubtitle(const std::string &str) {
	std::cout << std::endl << std::endl;
	std::cout << "~~~ " << str << " ~~~" << std::endl;
	std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl;
}

void runShrubberyFormTest() {
	try {
		Bureaucrat low("low", 142); // change to 42 to create file
		Bureaucrat high("high", 42);
		Bureaucrat tooLow("too low", 148); // change to 42 to create file

		ShrubberyCreationForm shrub("Tree");
		std::cout << low << std::endl;
		std::cout << high << std::endl;
		std::cout << tooLow << std::endl;
		std::cout << shrub << std::endl;

		printSubtitle("Execute ShrubberyForm with bureaucrat grade too low to execute");
		low.signForm(shrub);
		low.executeForm(shrub);

		printSubtitle("Execute ShrubberyForm with bureaucrat grade higher vs signed and exe.");
		high.signForm(shrub);
		std::cout << shrub << std::endl;
		ShrubberyCreationForm shrub1("Apple");
		high.signForm(shrub1);
		high.executeForm(shrub1);

		printSubtitle("Execute ShrubberyForm with bureaucrat grade too low.");
		ShrubberyCreationForm shrub2("Lemon");
		std::cout << shrub2 << std::endl;
		tooLow.signForm(shrub2);
		tooLow.executeForm(shrub2);
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void runRobotomyFormTest() {
	try {
		Bureaucrat low("low", 72);
		Bureaucrat high("high", 45);
		Bureaucrat tooLow("too low", 148);

		RobotomyRequestForm robot("Robot");
		std::cout << low << std::endl;
		std::cout << high << std::endl;
		std::cout << tooLow << std::endl;
		std::cout << robot << std::endl;

		printSubtitle("Execute RobotomyForm with bureaucrat grade too low to execute");
		low.signForm(robot);
		low.executeForm(robot);

		printSubtitle("Execute RobotomyForm with bureaucrat grade higher vs signed and exe.");
		high.signForm(robot);
		std::cout << robot << std::endl;
		high.executeForm(robot);

		printSubtitle("Execute RobotomyForm with bureaucrat grade too low");
		RobotomyRequestForm robot1("Robot 1");
		std::cout << robot1 << std::endl;
		tooLow.signForm(robot1);
		tooLow.executeForm(robot1);
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void runPresidentialFormTest() {
	try {
		Bureaucrat low("low", 6);
		Bureaucrat high("high", 4);
		Bureaucrat tooLow("too low", 30);

		PresidentialPardonForm presi("Presi");
		std::cout << low << std::endl;
		std::cout << high << std::endl;
		std::cout << tooLow << std::endl;
		std::cout << presi << std::endl;

		printSubtitle("Execute PresidentialForm with bureaucrat grade too low to execute");
		low.signForm(presi);
		low.executeForm(presi);
		std::cout << presi << std::endl;

		printSubtitle("Execute PresidentialForm with bureaucrat grade higher vs signed and exe.");
		high.signForm(presi);
		std::cout << presi << std::endl;
		high.executeForm(presi);

		printSubtitle("Execute PresidentialForm with bureaucrat grade too low");
		PresidentialPardonForm presi1("Presi 1");
		std::cout << presi1 << std::endl;
		tooLow.signForm(presi1);
		tooLow.executeForm(presi1);
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	std::srand(time(NULL)); // for Robotomy action
	printLine("Shrubbery Form Test");
	runShrubberyFormTest();
	printLine("Robotomy Form Test");
	runRobotomyFormTest();
	printLine("Presidential Form Test");
	runPresidentialFormTest();
	return 0;
}
