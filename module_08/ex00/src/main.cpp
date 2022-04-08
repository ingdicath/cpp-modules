//
// Created by Diana Salamanca on 31/03/2022.
//

#include "easyfind.hpp"
#include <iostream>
#include <exception>
#include <queue>
#include <vector>
#include <list>

void runDequeTest() {
	std::cout << PURPLE "Deque test at line " << __LINE__ << RESET << std::endl;

	std::deque<int> myDeque;
	for (int i = 1; i < 10; i++) {
		myDeque.push_back(i * 10);
	}
	printContainer(myDeque);

	try {
		std::deque<int>::iterator item = easyfind(myDeque, 70);
		std::cout << "First occurrence of item " GREEN << *item << RESET " found at index " GREEN
				  << std::distance(myDeque.begin(), item) << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void runListTest() {
	std::cout << std::endl;
	std::cout << PURPLE "List test at line " << __LINE__ << RESET << std::endl;

	std::list<int> myList;
	myList.push_back(6);
	myList.push_back(20);
	myList.push_back(6);
	printContainer(myList);

	try {
		std::list<int>::iterator item = easyfind(myList, 6);
		std::cout << "First occurrence of item " GREEN << *item << RESET " found at index " GREEN
				  << std::distance(myList.begin(), item) << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void runVectorTest() {
	std::cout << std::endl;
	std::cout << PURPLE "Vector test at line " << __LINE__ << RESET << std::endl;

	std::vector<int> myVector;
	for (int i = 1; i < 10; i++) {
		myVector.push_back(i * i);
	}
	printContainer(myVector);

	try {
		std::vector<int>::iterator item = easyfind(myVector, 64);
		std::cout << "First occurrence of item " GREEN << *item << RESET " found at index " GREEN
				  << std::distance(myVector.begin(), item) << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

int main() {
	runDequeTest();
	runListTest();
	runVectorTest();
	return 0;
}
