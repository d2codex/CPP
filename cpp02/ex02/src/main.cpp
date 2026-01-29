/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:31:04 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/29 23:39:09 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
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
		//ALLOWED RANGE: -8388607 to 8388606
		Fixed		a;
		Fixed const	b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;
/*
		{
			Fixed a(7.38f);
			Fixed b(-29);

			int	result = a != b; //true
			std::cout << a.toFloat() << " != " << b.toFloat() << '\n'
				<< result << std::endl;
		}
		{
			Fixed a(10);
			Fixed b(5.02f);

			Fixed& result = Fixed::max(a, b);

			std::cout << "max is " << result << '\n';
		}
		{
			Fixed a(10);
			Fixed b(10);

			Fixed& result = Fixed::min(a, b);
			result = Fixed(5);
			std::cout << "a: " << a.toFloat() << std::endl;
			std::cout << "b: " << b.toFloat() << std::endl;
			std::cout << "result: " << result << std::endl;
		}
*/
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << '\n'
				  << RESET;
		return (1);
	}

	return (0);
}
