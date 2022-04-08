//
// Created by Diana Salamanca on  01-Apr-22.
//

#include <iostream> // std::cout
#include <algorithm> // std::generate
#include <ctime> // std::time
#include <cstdlib> // std::rand, std::srand
#include "Span.hpp"

static void printSpans(const Span& obj){
	std::cout << "shortest span: " GREEN << obj.shortestSpan() << RESET << std::endl;
	std::cout << "longest span:  " GREEN << obj.longestSpan() << RESET << std::endl;
}

void runDefaultTest() {
	std::cout << PURPLE "'Default test' at line " << __LINE__ << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	printSpans(sp);

	std::cout << std::endl;
	std::cout << "~~~ 'Not enough elements' at line " << __LINE__ << " ~~~" << std::endl;
	try {
		Span sp1 = Span(1);
		sp1.addNumber(6);
		printSpans(sp1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "~~~ 'Maximum elements stored' at line " << __LINE__ << " ~~~" << std::endl;
	try {
		Span sp1 = Span(2);
		sp1.addNumber(-6);
		sp1.addNumber(-3);
		sp1.addNumber(10);
		printSpans(sp1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

// for generate random numbers
int randomNumber() {
	return (std::rand() % 1000000000 + 1);
}

void runRangeIteratorsTest() {
	std::cout << std::endl << std::endl;
	std::cout << PURPLE "'Large item test' at line " << __LINE__ << RESET << std::endl;
	std::srand(std::time(NULL)); // Providing a seed value

	// copy values from random vector into span
	Span sp = Span(15000);
	std::vector<int> vector1(15000);
	std::generate(vector1.begin(), vector1.end(), randomNumber);
	sp.addNumber(vector1.begin(), vector1.end());
	printSpans(sp);

	std::cout << std::endl;
	std::cout << "~~~ 'Not enough elements' at line " << __LINE__ << " ~~~" << std::endl;
	try {
		Span sp1 = Span(15000);
		std::vector<int> vector1(1);
		std::generate(vector1.begin(), vector1.end(), randomNumber);
		sp1.addNumber(vector1.begin(), vector1.end());
		printSpans(sp1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "~~~ 'Maximum elements stored' at line " << __LINE__ << " ~~~" << std::endl;
	try {
		Span sp2 = Span(15000);
		std::vector<int> vector1(15001);
		std::generate(vector1.begin(), vector1.end(), randomNumber);
		sp2.addNumber(vector1.begin(), vector1.end());
		printSpans(sp2);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

int main() {
	runDefaultTest();
	runRangeIteratorsTest();
	return 0;
}
