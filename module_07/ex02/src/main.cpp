//
// Created by Diana Salamanca on 29/03/2022.
//
#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750

void runDefaultTest() {
	std::cout << PURPLE "'Default test' at line " << __LINE__ << RESET << std::endl;
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return;
		}
	}
	try {
		numbers[-2] = 0;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
	delete[] mirror;
	std::cout << std::endl;
}

void runDeepCopyTest() {
	std::cout << PURPLE "'Deep copy test 2' at line " << __LINE__ << RESET << std::endl;
	unsigned int size = 4;
	Array<char> original(size);
	original[0] = 'a';
	original[1] = 'b';
	original[2] = 'c';
	original[3] = 'd';
	std::cout << "orig is: " GREEN << original << RESET << std::endl;

	Array<char> copy(original); // copy constructor
	std::cout << RESET "copy is: " GREEN << copy << RESET << std::endl;

	Array<char> twin(size);
	twin = original; // assigment operator
	std::cout << RESET "twin is: " GREEN << twin << RESET << std::endl;

	copy[2] = '.';
	std::cout << std::endl;
	std::cout << RESET "after changing one element in copy " << std::endl;
	std::cout << "orig is: " GREEN << original << std::endl;
	std::cout << RESET "copy is: " GREEN << copy << RESET << std::endl;
	std::cout << RESET "twin is: " GREEN << twin << RESET << std::endl;

	twin[0] = '*';
	std::cout << std::endl;
	std::cout << RESET "after changing one element in twin " << std::endl;
	std::cout << "orig is: " GREEN << original << std::endl;
	std::cout << RESET "copy is: " GREEN << copy << RESET << std::endl;
	std::cout << RESET "twin is: " GREEN << twin << RESET << std::endl;
}

int main(int, char **) {
	runDefaultTest();
	runDeepCopyTest();
	return 0;
}
