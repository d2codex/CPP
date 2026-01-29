/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:31:04 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/28 22:03:25 by diade-so         ###   ########.fr       */
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
/*		Fixed		a;
		Fixed const	b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << b << std::endl;

		Fixed c = b * 2;
		std::cout << c << std::endl;

		Fixed d = 5.05f * 2;
		std::cout << d << std::endl;

		//Fixed e = d / a;
		//std::cout << e << std::endl;

		Fixed f = -8388607.0f / -1;
		std::cout << f << std::endl;

		Fixed g(8388607);
		Fixed h(-8388607.0f);
		std::cout << h << std::endl;
		h = h / -1;
		std::cout << h << std::endl;
*/
	{
		Fixed i(8388606);
		std::cout << std::fixed << std::setprecision(0) << i << std::endl;
	}
	{
		Fixed i(-8388607);
		std::cout << std::setprecision(0) << i << std::endl;
	}
	{
		Fixed i(8388606.0f);
		std::cout << std::fixed << std::setprecision(1) << i << std::endl;
	}
	{
		Fixed i(-8388607.0f);
		std::cout << std::fixed << i << std::endl;
	}

//		 ALLOWED RANGE: -8388607 to 8388606
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << '\n'
				  << RESET;
		return (1);
	}

	return (0);
}
