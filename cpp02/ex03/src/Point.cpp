#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	LOG_DEBUG("Default constructor Called");
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	LOG_DEBUG("Point(x, y) constructor called");
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) 
{
	LOG_DEBUG("Copy constructor called");
}

Point::~Point()
{
	LOG_DEBUG("Destructor called");
}

Point::getX() const
{
	return (_x.x);
}

Point::getY() const
{
	return (_y.y);
}
