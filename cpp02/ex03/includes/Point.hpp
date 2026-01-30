#pragma once

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point& operator=(const Point&);
	~Point();

	const getX() const;
	const getY() const;

private:
	const Fixed	_x;
	const Fixed	_y;

	// required by subject, but unimplemented to prevent assignment
	// cannot be used because _x and _y are constant memebers
	Point(const Point& other);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point);
