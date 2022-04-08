//
// Created by Diana Salamanca on 03/04/2022.
//

#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <stack>
#include <list>

#pragma region utilfunctions
template<typename T>
void printObject(MutantStack<T> obj) {
	typename MutantStack<T>::iterator it = obj.begin();
	typename MutantStack<T>::iterator ite = obj.end();
	for (int index = 0; it != ite; ++it, index++) {
		std::cout << "index [" << index << "] = " << *it << std::endl;
	}
}

template<typename T>
void printObjectReverse(MutantStack<T> obj) {
	typename MutantStack<T>::reverseIterator rit = obj.rbegin();
	typename MutantStack<T>::reverseIterator rite = obj.rend();
	for (int index = 0; rit != rite; ++rit, index++) {
		std::cout << "index [" << index << "] = " << *rit << std::endl;
	}
}

template<typename T>
void printTopSize(MutantStack<T> obj, std::string const &str) {
	std::cout << "top " << str << " is: " GREEN << obj.top() << RESET
			  << " -- size " << str << " is: " GREEN << obj.size() << RESET << std::endl;
}
#pragma endregion

void runDefaultTest() {
	std::cout << std::endl;
	std::cout << PURPLE "****   'DEFAULT TEST' at line " << __LINE__ << "   ***" RESET << std::endl << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top org: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size org: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "original stack elements are: " << std::endl;
	printObject(mstack);
	printTopSize(mstack, "org");
	std::cout << std::endl;

	// using a normal stack to test MutantStack functionality
	std::stack<int> s(mstack);
	std::cout << "top s: " GREEN << s.top() << RESET " -- size s: " GREEN << s.size() << RESET << std::endl;
	std::cout << "top mstack: " GREEN << mstack.top()
			  << RESET " -- size mstack: " GREEN << mstack.size() << RESET << std::endl;

	std::cout << std::endl;
	std::cout << CYAN_L "~~~ 'copy const test' at line " << __LINE__ << " ~~~" RESET << std::endl;
	MutantStack<int> copy(mstack);
	copy.push(42);
	copy.pop();
	copy.pop();
	copy.pop();
	copy.push(2000);
	std::cout << "copy stack elements are: " << std::endl;
	printObject(copy);
	printTopSize(copy, "copy");
	printTopSize(mstack, "org"); //verifying original doesn't change

	std::cout << std::endl;
	std::cout << CYAN_L "~~~ 'assigment operator test' at line " << __LINE__ << " ~~~" RESET << std::endl;
	MutantStack<int> assig = mstack;
	assig.pop();
	assig.pop();
	assig.pop();
	assig.push(-36);
	std::cout << "assig stack elements are: " << std::endl;
	printObject(assig);
	printTopSize(assig, "assig");
	printTopSize(mstack, "org"); //verifying original doesn't change

	std::cout << std::endl;
	std::cout << CYAN_L "~~~ 'again original test' at line " << __LINE__ << " ~~~" RESET << std::endl;
	mstack.push(424242);
	std::cout << "org stack elements are: " << std::endl;
	printObject(mstack);
	printTopSize(mstack, "org");
	printTopSize(copy, "copy"); //verifying copy doesn't change
	printTopSize(assig, "assig");//verifying assig doesn't change
}

void runOtherTypeTest() {
	std::cout << std::endl << std::endl;
	std::cout << PURPLE "****   'USING LIST TEST' at line " << __LINE__ << "   ***" RESET << std::endl;
	std::list<int> myList;
	myList.push_back(5);
	myList.push_back(17);

	std::cout << std::endl;
	std::cout << "top: " << myList.back() << std::endl; //last element
	myList.pop_back();
	std::cout << "size: " << myList.size() << std::endl;
	myList.push_back(3);
	myList.push_back(5);
	myList.push_back(737);
	myList.push_back(0);

	std::list<int>::iterator it = myList.begin();
	std::list<int>::iterator ite = myList.end();
	std::cout << "list elements are: " << std::endl;
	for (int index = 0; it != ite; ++it, index++) {
		std::cout << "index [" << index << "] = " << *it << std::endl;
	}
	std::cout << "top: " GREEN << myList.back() << RESET " -- size: " GREEN << myList.size() << RESET << std::endl;
}

void runReverseIteratorTest() {
	std::cout << std::endl << std::endl;
	std::cout << PURPLE "****   'REVERSE ITERATOR TEST' at line " << __LINE__ << "   ***" RESET << std::endl;
	std::cout << std::endl;
	std::cout << CYAN_L "~~~ 'stack of integers test' at line " << __LINE__ << " ~~~" RESET << std::endl;

	MutantStack<int> integers;
	std::cout << "my initial integers:" << std::endl;
	for (int i = 1; i < 5; i++) { //filling the stack
		integers.push(i);
	}
	printObject(integers);
	std::cout << std::endl;
	std::cout << "my integers backwards:" << std::endl;
	printObjectReverse(integers);

	std::cout << std::endl;
	std::cout << CYAN_L "~~~ 'stack of strings test' at line " << __LINE__ << " ~~~" RESET << std::endl;
	MutantStack<std::string> strings;
	std::cout << "my initial strings:" << std::endl;
	strings.push("hi");
	strings.push("nice");
	strings.push("to");
	strings.push("meet");
	strings.push("you");
	printObject(strings);
	std::cout << std::endl;
	std::cout << "my strings backwards:" << std::endl;
	printObjectReverse(strings);
}

int main() {
	runDefaultTest();
	runOtherTypeTest();
	runReverseIteratorTest();
	return 0;
}
