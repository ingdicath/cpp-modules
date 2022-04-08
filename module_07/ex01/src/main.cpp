//
// Created by Diana Salamanca on 28/03/2022.
//

#include "iter.hpp"
#include <iostream>
#include <string>
#include <iomanip>

// this is a specific function for floats
static void dividedInHalf(float const &num) {
	float res = (num / 2);
	std::cout << std::setprecision(1) << std::fixed << res << " ";
}

// this is a specific function for int
static void powerInt(int const &num) {
	std::cout << num * num << " ";
}

void runIntArrayTest() {
	std::cout << PURPLE "Test 'int array' at line " << __LINE__ << RESET << std::endl;
	int num[] = {1, 2, 3, 4, 5, 6, 7};
	::iter(num, 7, print<int>);
	std::cout << std::endl;
	::iter(num, 7, printStyle<int>);
	std::cout << std::endl;
	::iter(num, 7, powerInt);
	std::cout << std::endl;
}

void runCharArrayTest() {
	std::cout << std::endl;
	std::cout << PURPLE "Test 'char array' at line " << __LINE__ << RESET << std::endl;
	char chars[] = {'a', 'b', 'c', '&', '|'};
	::iter(chars, 5, print<char>);
	std::cout << std::endl;
	::iter(chars, 5, printStyle<char>);
	std::cout << std::endl;
}

void runStringArrayTest() {
	std::cout << std::endl;
	std::cout << PURPLE "Test 'string array' at line " << __LINE__ << RESET << std::endl;
	std::string strings[] = {"ik", "ben", "Diana,", "yo", "soy", "Diana"};
	::iter(strings, 6, print<std::string>);
	std::cout << std::endl;
	::iter(strings, 6, printStyle<std::string>);
	std::cout << std::endl;
}

void runFloatArrayTest() {
	std::cout << std::endl;
	std::cout << PURPLE "Test 'float array' at line " << __LINE__ << RESET << std::endl;
	float num[] = {10.f, 25.568f, 42.42f, -36.12f};
	::iter(num, 4, printStyle<float>);
	std::cout << std::endl;
	::iter(num, 4, dividedInHalf);
	std::cout << std::endl;
}

int main() {
	runIntArrayTest();
	runCharArrayTest();
	runStringArrayTest();
	runFloatArrayTest();
	return 0;
}


/*
class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];

	iter( tab, 5, print );
	iter( tab2, 5, print );

	return 0;
}
*/
