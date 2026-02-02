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
/*
	{
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
*/
	{
		ClapTrap a("Sandy");
		a.takeDamage(9);
		a.beRepaired(UINT_MAX);
		a.takeDamage(UINT_MAX);
	}
}
