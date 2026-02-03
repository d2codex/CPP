#include "Logger.hpp"
#include "colors.hpp"
#include "FragTrap.hpp"
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

	// default constructors show parent and child initialized values
	// destructors called in reverse order (parent first - unless virtual)
	{
		std::cout << cyn("====== Test[1]: default ctor / dtor ======\n");
		ClapTrap();
		FragTrap();
	}
	// String constructor
	{
		std::cout << cyn("======= Test[2]: name constructor ========\n");
		FragTrap("Squidward");
	}
	// Copy Constructor
	{
		std::cout << cyn("======= Test[3]: copy constructor ========\n");
		FragTrap a("SpongeBob");
		FragTrap b(a);
	}
	// Assignment Constructor
	{
		std::cout << cyn("===== Test[4]: assignment constructor ====\n");
		FragTrap gary("Gary");
		FragTrap mrKrabs("Mr. Krabs");

		mrKrabs = gary;
	}
	// High-five Mode
	{
		std::cout << cyn("======= Test[5]: High Five Guys Mode ======\n");
		FragTrap plankton("Plankton");
		plankton.highFiveGuys();
	}
	// Attack
	{
		std::cout << cyn("=========== Test[6]: Atack Mode ===========\n");
		FragTrap kamazi("Kamikaze Claptrap");
		kamazi.attack("Stabby Claptrap");
		kamazi.takeDamage(50);
		kamazi.takeDamage(100);
		kamazi.beRepaired(100);
		kamazi.attack("FL4k");
	}
}
