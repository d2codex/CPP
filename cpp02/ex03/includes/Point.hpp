#pragma once

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	// required by subject, but unimplemented to prevent assignment
	// cannot be used because _x and _y are constant memebers
	// also this should be in the private sector
	Point& operator=(const Point&);
	~Point();

	const Fixed& getX() const;
	const Fixed& getY() const;

private:
	Fixed const	_x;
	Fixed const	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
