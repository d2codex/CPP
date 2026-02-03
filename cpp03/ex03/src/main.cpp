#include "Logger.hpp"
#include "colors.hpp"
#include "DiamondTrap.hpp"
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
		DiamondTrap();
	}
	// Name constructor
	{
		std::cout << cyn("======= Test[2]: name constructor ========\n");
		DiamondTrap("Squidward");
	}
	// Copy Constructor
	{
		std::cout << cyn("======= Test[3]: copy constructor ========\n");
		DiamondTrap a("SpongeBob");
		DiamondTrap b(a);
	}
	// Assignment Constructor
	{
		std::cout << cyn("===== Test[4]: assignment constructor ====\n");
		DiamondTrap gary("Gary");
		DiamondTrap mrKrabs("Mr. Krabs");

		mrKrabs = gary;
	}
	// Who Am I?
	{
		std::cout << cyn("============== Test[5]: whoAmI ============\n");
		DiamondTrap plankton("Plankton");
		plankton.whoAmI();
	}
	// Attack
	{
		std::cout << cyn("=========== Test[6]: Atack Mode ===========\n");
		DiamondTrap patrick("Patrick");
		patrick.attack("Stabby Claptrap");
		ClapTrap spongebob("SpongeBobSquarePants");
		ScavTrap gary("Gary");
		FragTrap plankton("Plankton");
	}
}
