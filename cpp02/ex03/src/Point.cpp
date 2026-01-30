/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 23:46:59 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/30 23:47:01 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes the point at the origin (0, 0).
 */
Point::Point() : _x(0), _y(0)
{
	LOG_DEBUG("Default constructor Called");
}


/**
 * @brief Constructs a point from floating-point coordinates.
 *
 * @param x X coordinate.
 * @param y Y coordinate.
 */
Point::Point(const float x, const float y) : _x(x), _y(y)
{
	LOG_DEBUG("Point(x, y) constructor called");
}


/**
 * @brief Copy constructor.
 *
 * Initializes a new point by copying another point.
 *
 * @param other Point to copy from.
 */
Point::Point(const Point& other) : _x(other._x), _y(other._y) 
{
	LOG_DEBUG("Copy constructor called");
}

/**
 * @brief Destructor.
 */
Point::~Point()
{
	LOG_DEBUG("Destructor called");
}

/**
 * @brief Returns the x coordinate.
 *
 * @return Constant reference to the x coordinate.
 */
const Fixed& Point::getX() const
{
	return (_x);
}

/**
 * @brief Returns the y coordinate.
 *
 * @return Constant reference to the y coordinate.
 */
const Fixed& Point::getY() const
{
	return (_y);
}
