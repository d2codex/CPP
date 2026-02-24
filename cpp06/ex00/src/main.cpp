/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:03:52 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/24 16:03:54 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <stdexcept>

bool initLogger(int argc, char **argv)
{
	if (argc == 2)
	{
		Logger::get().setThreshold(Logger::NONE);
		return (true);
	}
	if (argc == 3)
	{
		Logger::logLevel level = Logger::stringToLevel(argv[2]);
		if (level == Logger::INVALID)
		{
			std::cout << red("Error. invalid log level\n");
			std::cout << cyn("usage: ./bin/<program_name> [argument] [log level]\n");
			std::cout << cyn("log levels: debug(debug build only) info warning\n");
			return (false);
		}
		#ifndef DBUG
		if (level == Logger::DEBUG)
		{
			std::cout << mag("Warning: DEBUG messages are not enabled in this build.\n");
			Logger::get().setThreshold(Logger::INFO); // fallback threshold
			return (true);
		}
		#endif
		Logger::get().setThreshold(level);
		return (true);
	}
	std::cout << cyn("usage: ./bin/<program_name> [argument] [log level]\n");
	std::cout << cyn("log levels: debug(debug build only) info warning\n");
	return (false);
}

int	main(int argc, char **argv)
{
	if (!initLogger(argc, argv))
		return (1);

	const std::string input = argv[1];
	try
	{
		ScalarConverter::convert(input);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}
