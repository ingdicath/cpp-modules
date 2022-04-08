//
// Created by Diana Salamanca on 21-03-2022.
//

#ifndef CONVERTER_HPP
#define CONVERTER_HPP
# define RED "\033[0;31m"
# define RESET "\033[0m"

#include <string>

/* 					Check types					*/
bool isSpecialValue(const std::string &input);

bool isInvalidSpecial(const std::string &input);

bool isValidInput(std::string input);

bool isChar(const std::string &input);

bool isFloat(std::string input);


/* 					Print types					*/
void printChar(std::string input);

void printSpecial(const std::string &input);

void printConversion(const std::string &input);

void printNumber(const std::string &input);

#endif
