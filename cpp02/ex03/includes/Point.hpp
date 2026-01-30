/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 23:49:06 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/30 23:49:08 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

/**
 * @brief Immutable 2D point using fixed-point coordinates.
 *
 * Represents a point in a 2D plane. Coordinates are stored as constant
 * Fixed values, making the object immutable after construction.
 *
 * The copy assignment operator is declared only to satisfy the subject
 * requirements. It is intentionally not implemented because the point
 * owns constant members and therefore cannot be reassigned.
 */
class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	Point& operator=(const Point&);
	~Point();

	const Fixed& getX() const;
	const Fixed& getY() const;

private:
	Fixed const	_x;
	Fixed const	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
