/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:31:51 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/30 23:45:07 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "colors.hpp"
#include <iostream>

/**
 * @brief Computes the 2D cross product of vectors start->end and start->p.
 *
 * The sign of the result indicates whether p lies to the left or right
 * of the directed edge (start -> end). A zero value means collinear.
 *
 * @param start Origin of both vectors.
 * @param end   End point of the edge vector.
 * @param p     End point of the test vector.
 * @return Signed cross product as Fixed.
 */
static Fixed crossProduct(Point const& start, 
                          Point const& end, 
                          Point const& p)
{
    return ((end.getX() - start.getX()) * (p.getY() - start.getY())
          - (end.getY() - start.getY()) * (p.getX() - start.getX()));
}

/**
 * @brief Determines if a point lies strictly inside a triangle.
 *
 * Uses cross products to test whether the point lies on the same side
 * of all triangle edges. Points on edges are considered outside.
 * Degenerate triangles always return false.
 *
 * @param a First triangle vertex.
 * @param b Second triangle vertex.
 * @param c Third triangle vertex.
 * @param point Point to test.
 * @return true if point is strictly inside, false otherwise.
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// degenerate triangle detection
	Fixed area = crossProduct(a, b, c);
	if (area == 0)
	{
		LOG_INFO("Triangle is degenerate");
		return (false);
	}
    Fixed ab_ap = crossProduct(a, b, point);
    Fixed bc_bp = crossProduct(b, c, point);
    Fixed ca_cp = crossProduct(c, a, point);

	if (ab_ap == 0 || bc_bp == 0 || ca_cp == 0)
	{
		LOG_INFO("point is on the edge of the triangle (outside)");
		return (false);
	}

	bool allPositive = (ab_ap > 0 && bc_bp > 0 && ca_cp > 0);
	bool allNegative = (ab_ap < 0 && bc_bp < 0 && ca_cp < 0);

	if (allPositive || allNegative)
	{
		LOG_INFO("point is inside the triangle");
		return (true);
	}
	LOG_INFO("point is outside the triangle");
	return (false);
}
