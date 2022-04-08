//
// Created by Diana Salamanca on 21-03-2022.
//

#include "PrintTypes.hpp"
#include <iostream>

static void printError(const std::string &c1, const std::string &str) {
	std::cerr << c1 << str << RESET << std::endl;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		printError(RED, "One argument is expected.");
		return EXIT_FAILURE;
	}
	std::string input = static_cast<std::string>(argv[1]);
	if (input.empty() || isInvalidSpecial(input)) {
		printError(RED, "Only valid values are char, int, float or double.");
		return EXIT_FAILURE;
	} else if (isSpecialValue(input)) {
		printSpecial(input);
	} else if (isValidInput(input)) {
		printConversion(input);
	} else {
		printError(RED, "Only valid values are char, int, float or double.");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
