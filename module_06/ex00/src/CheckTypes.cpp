//
// Created by Diana Salamanca on 27-03-2022.
//

#include "PrintTypes.hpp"
#include <ios> // noskipws, fail, eof
#include <sstream> // istringstream
#include <string>

bool isSpecialValue(const std::string &input) {
	std::string special[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (int i = 0; i < 6; i++) {
		if (input == special[i]) {
			return true;
		}
	}
	return false;
}

bool isInvalidSpecial(const std::string &input) {
	std::string invalidSpecial[] = {"inff", "inf", "-nan", "+nan", "-nanf", "+nanf"};
	for (int i = 0; i < 6; i++) {
		if (input == invalidSpecial[i]) {
			return true;
		}
	}
	return false;
}

/**
 * fail(): check whether either failbit (Logical error on i/o operation)
 * or badbit (Read/writing error on i/o operation) is set.
 *
 * eof(): Check whether eofbit (End-of-File reached on input operation) is set.
 */
bool isValidInput(std::string input) {
	if (input.length() == 1) {
		return true;
	} else if (input[input.length() - 1] == 'f') {
		input = input.substr(0, input.length() - 1);
	}
	double result;
	std::istringstream i(input);
	i >> std::noskipws >> result;
	return !i.std::ios::fail() && i.std::ios::eof();
}

bool isChar(const std::string &input) {
	return (input.length() == 1);
}

bool isFloat(std::string input) {
	return (input[input.length() - 1] == 'f');
}
