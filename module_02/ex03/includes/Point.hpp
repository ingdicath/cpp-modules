//
// Created by Diana Salamanca on 28/02/2022.
//

#ifndef POINT_HPP
#define POINT_HPP

# include "../includes/Fixed.hpp"

class Point {
public:
	Point();

	Point(float const x, float const y);

	Point(Point const &obj);

	Point &operator=(Point const &obj);

	~Point();

	bool operator==(const Point &obj) const;

	Fixed getX() const;

	Fixed getY() const;

private:
	Fixed const _x;
	Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

Fixed sign(const Point &p1, const Point &p2, const Point &p3);

#endif
