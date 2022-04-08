//
// Created by Diana Salamanca on 28-Mar-22.
//

#include "whatever.hpp"
#include <iostream>

void runTestInteger() {
	int a = 2;
	int b = 3;
	std::cout << CYAN_L "'Integer test' at line " << __LINE__ << RESET << std::endl;
	std::cout << "before swap-> a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "after swap-> a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
}

void runTestString() {
	std::cout << std::endl;
	std::cout << CYAN_L "'String test' at line " << __LINE__ << RESET << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "before swap-> c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "after swap-> c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

void runTestDouble() {
	std::cout << std::endl;
	std::cout << CYAN_L "'Double test' at line " << __LINE__ << RESET << std::endl;
	double db1 = 3.6;
	double db2 = -42.42;
	std::cout << "before swap-> db1 = " << db1 << ", db2 = " << db2 << std::endl;
	::swap(db1, db2);
	std::cout << "after swap-> db1 = " << db1 << ", db2 = " << db2 << std::endl;
	std::cout << "min( db1, db2 ) = " << ::min(db1, db2) << std::endl;
	std::cout << "max( db1, db2 ) = " << ::max(db1, db2) << std::endl;
}

void runTestBoolean() {
	std::cout << std::endl;
	std::cout << CYAN_L "'Boolean test' at line " << __LINE__ << RESET << std::endl;
	bool b1 = true;
	bool b2 = false;
	std::cout << "before swap-> b1 = " << b1 << ", b2 = " << b2 << std::endl;
	::swap(b1, b2);
	std::cout << "after swap-> b1 = " << b1 << ", b2 = " << b2 << std::endl;
	std::cout << "min( b1, b2 ) = " << ::min(b1, b2) << std::endl;
	std::cout << "max( b1, b2 ) = " << ::max(b1, b2) << std::endl;
}

int main() {
	runTestInteger();
	runTestString();
	runTestDouble();
	runTestBoolean();
	return 0;
}

/*
class Awesome
{
public:
	Awesome(void) : _n(0) {}
	Awesome( int n ) : _n( n ) {}
	Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
	bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
	bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
	bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
	bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
	bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
	bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
	int get_n() const { return _n; }
private:
	int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
	Awesome a(2), b(4);

	swap(a, b);
	std::cout << a << " " << b << std::endl;
	std::cout << max(a, b) << std::endl;
	std::cout << min(a, b) << std::endl;
	return (0);
}
*/
