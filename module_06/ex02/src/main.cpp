#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>
#include <cstdlib> // std::rand, std::srand
#include <ctime> // std::time
#include <exception> //std::exception

/**
 * Dynamic_cast can only be used with pointers and references to classes (or with void*).
 * Its purpose is to ensure that the result of the type conversion
 * points to a valid complete object of the destination pointer type.
 * To work on dynamic_cast there must be one virtual function in the base class (polymorphic classes).
 * Downcast -> convert from pointer-to-base to pointer-to-derived.
 * Upcast -> converting from pointer-to-derived to pointer-to-base.
 */

static void printStr(const std::string &c1, const std::string &str) {
	std::cout << c1 << str << RESET << std::endl;
}

static void checkLeaks() {
	std::cout << std::endl;
	printStr(ORANGE, "Checking for leaks......");
	system("leaks realtype");
}

Base *generate() {
	std::srand(std::time(NULL)); // Providing a seed value
	int random = std::rand() % 3;
	switch (random) {
		case 0:
			printStr(GREEN, "A was generated");
			return new A();
		case 1:
			printStr(GREEN, "B was generated");
			return new B();
		case 2:
			printStr(GREEN, "C was generated");
			return new C();
		default:
			return ¸;
	}
}

/** downcasting in each case **/
void identify(Base *p) {
	A *ptrA = dynamic_cast<A *>(p);
	if (ptrA != NULL) {
		printStr(PURPLE, "A");
		return;
	}
	B *ptrB = dynamic_cast<B *>(p);
	if (ptrB != NULL) {
		printStr(PURPLE, "B");
		return;
	}
	C *ptrC = dynamic_cast<C *>(p);
	if (ptrC != NULL) {
		printStr(PURPLE, "C");
		return;
	}
}

void identify(Base &p) {
	try {
		A &refA = dynamic_cast<A &>(p);
		(void) refA;
		printStr(ORANGE, "A");
	} catch (std::exception &e) {}
	try {
		B &refB = dynamic_cast<B &>(p);
		(void) refB;
		printStr(ORANGE, "B");
	} catch (std::exception &e) {}
	try {
		C &refC = dynamic_cast<C &>(p);
		(void) refC;
		printStr(ORANGE, "C");
	} catch (std::exception &e) {}
}

int main() {
	Base *basePtr = generate();
	Base &baseRef = *basePtr;

	std::cout << "Type (pointer): ";
	identify(basePtr);

	std::cout << "Type (reference): ";
	identify(baseRef);

	delete basePtr;
	checkLeaks();
	return 0;
}
