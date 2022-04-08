//
// Created by Diana Salamanca on 12/02/2022.
//

#include "../includes/Karen.hpp"

Karen::Karen() {
}

Karen::~Karen() {
}

void Karen::debug() {
	std::cout << PURPLE << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
				 "7XL-double-cheese-triple-pickle-specialketchup burger. "
				 "I really do!"
			  << RESET << std::endl;
}

void Karen::info() {
	std::cout << CYAN << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
				 "You didn’t put enough bacon in my burger! "
				 "If you did, I wouldn’t be asking for more!"
			  << RESET << std::endl;
}

void Karen::warning() {
	std::cout << ORANGE << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."
				 "I’ve been coming for years whereas you started working here"
				 "since last month."
			  << RESET << std::endl;
}

void Karen::error() {
	std::cout << RED << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << RESET << std::endl;
}

void Karen::complain(std::string level) {
	std::string commentLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Karen::*funMemPtr[])() = {&Karen::debug,
									&Karen::info,
									&Karen::warning,
									&Karen::error};
	for (int i = 0; i < 4; i++) {
		if (commentLevels[i] == level)
			(this->*funMemPtr[i])();
	}
}
