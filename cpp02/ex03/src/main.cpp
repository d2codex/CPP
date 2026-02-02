/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:31:04 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/30 23:20:20 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <cstdlib>
#include <iostream>
#include <climits>
#include <iomanip>

/**
 * @brief Initialize the logger threshold from command line args.
 *
 * If no log level is provided, logging is disabled (NONE).
 * If a valid log level is provided, the threshold is set.
 * Otherwise, prints usage and returns false.
 *
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @return true on success, false on error.
 */
static bool initLogger(int argc, char **argv)
{
	if (argc == 1)
	{
		Logger::setThreshold(Logger::NONE);
		return (true);
	}
	if (argc == 2)
	{
		Logger::logLevel level = Logger::stringToLevel(argv[1]);
		if (level == Logger::INVALID)
		{
			std::cout << red("Error: Invalid log level\n");
			std::cout << cyn("Usage: ./bin/bsp [log level]\n")
					  << cyn("Log modes: debug info warning error none\n");
			return (false);
		}
		Logger::setThreshold(level);
		return (true);
	}
	std::cout << cyn("Usage: ./bin/bsp [log level]\n");
	std::cout << cyn("Log modes: debug info warning error none\n");
	return (false);
}

int main(int argc, char **argv)
{
	if (!initLogger(argc, argv))
		return (1);
	try
	{
		// normal case - point inside
		{
			Point a(0,0);
			Point b(2,3);
			Point c(0,3);
			Point point(1,2);

			if (bsp(a, b, c, point))
				std::cout << yel("point is inside the triangle\n");
			else
				std::cout << mag("point is outside the triangle\n");
		}
		// normal case - point outside
		{
			Point a(0,0);
			Point b(2,3);
			Point c(0,3);
			Point point(-1,2);

			if (bsp(a, b, c, point))
				std::cout << yel("point is inside the triangle\n");
			else
				std::cout << mag("point is outside the triangle\n");
		}
		// point is on the edge / line (point outside)
		{
			Point a(0,0);
			Point b(2,3);
			Point c(0,3);
			Point point(0,2);

			if (bsp(a, b, c, point))
				std::cout << yel("point is inside the triangle\n");
			else
				std::cout << mag("point is outside the triangle\n");
		}
		// triangle is degenerate (point outside)
		{
			Point a(3,3);
			Point b(2,3);
			Point c(0,3);
			Point point(0,2);

			if (bsp(a, b, c, point))
				std::cout << yel("point is inside the triangle\n");
			else
				std::cout << mag("point is outside the triangle\n");
		}
		//slightly outside
		{
			Point a(0.0f, 0.0f);
			Point b(10.0f, 0.0f);
			Point c(5.0f, 10.0f);
			Point point(5.0f, 10.00001f);
			if (bsp(a, b, c, point))
				std::cout << yel("point is inside the triangle\n");
			else
				std::cout << mag("point is outside the triangle\n");
		}
		//slightly inside
		{
			Point a(0.0f, 0.0f);
		    Point b(0.0f, 3.0f);
			Point c(3.0f, 0.0f);
			Point point(0.002f, 1.41);
			if (bsp(a, b, c, point))
				std::cout << yel("point is inside the triangle\n");
			else
				std::cout << mag("point is outside the triangle\n");
		}

	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << '\n'
				  << RESET;
		return (1);
	}
	return (0);
}
