//
// Created by Diana Salamanca on 18/02/2022.
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

/**
 * A switch statement can only be used for integer values, not for values of user-defined type.
 * Mapping the strings to enum values(integers), allows using them in switch case.
 */
Karen::Level Karen::resolveLevel(const std::string &level) {
	if (level == "DEBUG")
		return DEBUG;
	else if (level == "INFO")
		return INFO;
	else if (level == "WARNING")
		return WARNING;
	else if (level == "ERROR")
		return ERROR;
	return OPTION_INVALID;
}

void Karen::complain(std::string level) {
	switch (resolveLevel(level)) {
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
					  << std::endl;
	}
}
