/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:18:26 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:30 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "colors.hpp"
#include <cstdlib>
#include <iostream>

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
			std::cout << RED("Error: Invalid log level\n");
			std::cout << CYN("Usage: ./bin/fixed [log level]\n")
					  << CYN("Log modes: debug info warning error none\n");
			return (false);
		}
		Logger::setThreshold(level);
		return (true);
	}
	std::cout << CYN("Usage: ./bin/Fixed [log level]\n");
	std::cout << CYN("Log modes: debug info warning error none\n");
	return (false);
}

int main(int argc, char **argv)
{
	if (!initLogger(argc, argv))
		return (1);

	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	b = b;
}
