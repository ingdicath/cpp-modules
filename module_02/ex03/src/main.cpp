//
// Created by Diani on 01/03/2022.
//

#include "../includes/Point.hpp"
#include <iostream>

int main() {
	Point a(0, 5);
	Point b;
	Point c(5, 0);
	Point in(0.554688, 0.0117188);
	Point out(-1.5, 4.5);
	Point ed(3, 0);
	bool res;

	res = bsp(a, b, c, in);
	std::cout << GREEN "Point in triangle: " << std::boolalpha << res << std::endl;

	res = bsp(a, b, c, out);
	std::cout << RESET "\nPoint is out of triangle." << std::endl;
	std::cout << "Point in triangle: " << std::boolalpha << res << std::endl;

	res = bsp(a, b, c, b);
	std::cout << ORANGE "Point in triangle: " << std::boolalpha << res << std::endl;

	res = bsp(a, b, c, ed);
	std::cout << "\nPoint is on a triangle edge." << std::endl;
	std::cout << "Point in triangle: " << std::boolalpha << res << std::endl;
	return 0;
}
