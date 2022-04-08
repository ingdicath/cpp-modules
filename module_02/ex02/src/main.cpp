//
// Created by Diana catherine Salamanca leguizamon on 2/24/22.
//

#include "../includes/Fixed.hpp"
#include <iostream>
#include <string>

static void printMessage(const std::string &s1, const Fixed &num1, const Fixed &num2, const Fixed &res) {
	std::cout << s1 << YELLOW << num1 << RESET " and " YELLOW
			  << num2 << RESET " is " YELLOW << res << RESET << std::endl;
}

static void printComparison(const std::string &s1, const Fixed &num1, const Fixed &num2) {
	std::cout << s1 << YELLOW << num1 << RESET " and " YELLOW << num2
			  << RESET " is ";
}

static void runTestComparisonOp(const Fixed &x, const Fixed &y) {
	std::cout << CYAN "** Comparison operators **" RESET << std::endl;
	printComparison("Operator == between \t", x, y);
	std::cout << std::boolalpha << YELLOW << (x == y) << RESET << std::endl;
	printComparison("Operator != between \t", x, y);
	std::cout << std::boolalpha << YELLOW << (x != y) << RESET << std::endl;
	printComparison("Operator > between \t", x, y);
	std::cout << std::boolalpha << YELLOW << (x > y) << RESET << std::endl;
	printComparison("Operator < between \t", x, y);
	std::cout << std::boolalpha << YELLOW << (x < y) << RESET << std::endl;
	printComparison("Operator <= between \t", x, y);
	std::cout << std::boolalpha << YELLOW << (x <= y) << RESET << std::endl;
	printComparison("Operator >= between \t", x, y);
	std::cout << std::boolalpha << YELLOW << (x >= y) << RESET << std::endl;
}

static void runTestArithmeticOp(const Fixed &x, const Fixed &y) {
	std::cout << PURPLE "\n** Arithmetic operators **" RESET << std::endl;
	printMessage("Operator + between \t", x, y, (x + y));
	printMessage("Operator - between \t", x, y, (x - y));
	printMessage("Operator * between \t", x, y, (x * y));
	printMessage("Operator / between \t", x, y, (x / y));
}

static void runTestIncrementOp(Fixed &a) {
	std::cout << ORANGE "\n** Increment operators **" RESET << std::endl;
	std::cout << "a is \t" << a << std::endl;
	std::cout << "++a is \t" << ++a << std::endl;
	std::cout << "a is \t" << a << std::endl;
	std::cout << "a++ is \t" << a++ << std::endl;
	std::cout << "a is \t" << a << std::endl;
}

static void runTestDecrementOp(Fixed &a) {
	std::cout << ORANGE "\n** Decrement operators **" RESET << std::endl;
	std::cout << "a is \t" << a << std::endl;
	std::cout << "--a is \t" << --a << std::endl;
	std::cout << "a is \t" << a << std::endl;
	std::cout << "a-- is \t" << a-- << std::endl;
	std::cout << "a is \t" << a << std::endl;
}

static void runTestMinMax() {
	Fixed const x(Fixed(5.05f) * Fixed(2));
	Fixed y(3);
	Fixed z(7.8f);

	std::cout << GREEN "\n** Min y max **" RESET << std::endl;
	std::cout << GRAY "Constant number" RESET << std::endl;
	printMessage("min between ", x, y, Fixed::min(x, y));
	printMessage("max between ", x, y, Fixed::max(x, y));
	std::cout << GRAY "\nNon-constant number" RESET << std::endl;
	printMessage("min between ", y, z, Fixed::min(y, z));
	printMessage("max between ", y, z, Fixed::max(y, z));
}

int main() {
	Fixed a;
	Fixed x(3.5f);
	Fixed y(2);

	runTestComparisonOp(x, y);
	runTestArithmeticOp(x, y);
	runTestIncrementOp(a);
	runTestDecrementOp(a);
	runTestMinMax();
	return 0;
}
