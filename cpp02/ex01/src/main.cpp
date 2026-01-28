/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:31:04 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/28 16:47:24 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "colors.hpp"
#include <cstdlib>
#include <iostream>
#include <climits>

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
			std::cout << cyn("Usage: ./bin/fixed [log level]\n")
					  << cyn("Log modes: debug info warning error none\n");
			return (false);
		}
		Logger::setThreshold(level);
		return (true);
	}
	std::cout << cyn("Usage: ./bin/Fixed [log level]\n");
	std::cout << cyn("Log modes: debug info warning error none\n");
	return (false);
}

int main(int argc, char **argv)
{
	if (!initLogger(argc, argv))
		return (1);
	try
	{
		Fixed a;
		Fixed const b( 10 ); //int constructor
		Fixed const c( 42.42f ); // float constructor
		Fixed const d( b ); // copy constructor

		a = Fixed( 1234.4321f ); //float constructor

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;

//		Fixed allowedMax(8388607);
//		Fixed max(INT_MAX);
//		Fixed allowedMin(-8388608);
//		Fixed min(INT_MIN);
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << '\n'
				  << RESET;
		return (1);
	}

	return (0);
}
