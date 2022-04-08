//
// Created by Diana Salamanca on 21-03-2022.
//

#include "PrintTypes.hpp"
#include <iostream> // cout, fixed
#include <sstream> // istringstream
#include <iomanip> // setprecision
#include <string>
#include <cfloat>

void printSpecial(const std::string &input) {
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	if (input == "-inf" || input == "+inf" || input == "nan") {
		std::cout << "float: " << input << "f" << std::endl;
	} else {
		std::cout << "float: " << input << std::endl;
	}
	if (input == "-inff" || input == "+inff" || input == "nanf") {
		std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
	} else {
		std::cout << "double: " << input << std::endl;
	}
}

/**
 * fixed: write floating-point values in fixed-point notation.
 * setprecision: sets the decimal precision to be used to format floating-point values.
 */
void printChar(std::string input) {
	char c = input[0];
	if (!std::isdigit(c) && std::isprint(c)) {
		std::cout << "char: '" << c << "'" << std::endl;
	} else if (std::isdigit(c)) {
		printNumber(input);
		return;
	}
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(c) << std::endl;
}

/**
 * - The std::stringstream acts just like std::cin but instead of getting the input from the user
 * you load it into the stream with a std::string.
 * - In floating-point the negative value with the greatest magnitude is -FLT_MAX or -DBL_MAX.
 * - Printable chars https://en.wikipedia.org/wiki/ASCII
 */
void printNumber(const std::string &input) {
	std::istringstream ss(input);
	double res;
	ss >> res;

	if (res > 31 && res < 127)
		std::cout << "char: '" << static_cast<char>(res) << "'" << std::endl;
	else if (res >= 0 && res < 32) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: impossible" << std::endl;
	}

	if (res > INT_MAX || res < INT_MIN) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(res) << std::endl;
	}
	if (res > FLT_MAX || res < -FLT_MAX) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(res) << "f" << std::endl;
	}
	if (res > DBL_MAX || res < -DBL_MAX) {
		std::cout << "double: impossible" << std::endl;
	} else {
		std::cout << "double: " << std::setprecision(1) << std::fixed << res << std::endl;
	}
}

void printConversion(const std::string &input) {
	std::string temp = input;
	if (isChar(input)) {
		printChar(input);
		return;
	}
	if (isFloat(input)) {
		temp = input.substr(0, input.length() - 1);
	}
	printNumber(temp);
}
