//
// Created by Diani on 28/02/2022.
//

#include "../includes/Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(float const x, float const y) : _x(x), _y(y) {
}

Point::Point(const Point &obj) : _x(obj._x), _y(obj._y) {
}

Point &Point::operator=(const Point &obj) {
	if (this != &obj) {
	}
	return *this;
}

bool Point::operator==(const Point &obj) const {
	return (this->_x == obj.getX() && this->_y == obj.getY());
}

Point::~Point() {
}

Fixed Point::getX() const {
	return this->_x;
}

Fixed Point::getY() const {
	return this->_y;
}
