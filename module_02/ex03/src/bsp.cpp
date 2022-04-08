//
// Created by Diani on 28/02/2022.
//

#include "../includes/Point.hpp"
#include <iostream>

Fixed sign(const Point &p1, const Point &p2, const Point &p3) {
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
		   - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed ab, bc, ca;
	bool isNeg, isPos;

	if (a == b || b == c || c == a) {
		std::cout << RED "\nPoints are not able to make a triangle." RESET << std::endl;
		return false;
	}
	if (point == a || point == b || point == c) {
		std::cout << ORANGE "\nPoint is on a triangle vertex." RESET << std::endl;
		return false;
	}
	ab = sign(point, a, b);
	bc = sign(point, b, c);
	ca = sign(point, c, a);

	isNeg = (ab < 0) && (bc < 0) && (ca < 0);
	isPos = (ab > 0) && (bc > 0) && (ca > 0);
	return (isNeg || isPos);
}
