/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:33:46 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/04 00:33:54 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "colors.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <climits>

bool initLogger(int argc, char **argv)
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
			std::cout << red("Error. invalid log level\n");
			std::cout << cyn("usage: ./bin/claptrap [log level]\n");
			std::cout << cyn("log levels: debug info warning error\n");
			return (false);
		}
		Logger::setThreshold(level);
		return (true);
	}

	std::cout << cyn("usage: ./bin/claptrap [log level]\n");
	std::cout << cyn("log levels: debug info warning error\n");
	return (false);
}

int	main(int argc, char **argv)
{
	if (!initLogger(argc, argv))
		return (1);

	{
		std::cout << cyn("====== Test[1]: attack / beRepaired ======\n");
		ClapTrap a("Patrik");
		a = a;
		ClapTrap b(a);
		a.beRepaired(1);
		a.attack("Plankton");
		a.attack("Plankton");
		a.attack("Plankton");
		a.attack("Plankton");
		a.attack("Plankton");
		a.attack("Plankton");
		a.attack("Plankton");
		a.attack("Plankton");
		a.beRepaired(UINT_MAX);
		a.beRepaired(100);
	}

	{
		std::cout << cyn("========= Test[2]: takeDamage =========\n");
		ClapTrap a("Sandy");
		a.takeDamage(9);
		a.beRepaired(UINT_MAX);
		a.takeDamage(UINT_MAX);
	}
}
