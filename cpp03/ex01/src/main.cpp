#include "Logger.hpp"
#include "colors.hpp"
//#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
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
		ScavTrap();
	}
	// String constructor
	{
		std::cout << cyn("====== Test[2]: string constructor ======\n");
		ScavTrap("Squidward");
	}
	// Copy Constructor
	{
		std::cout << cyn("======= Test[3]: copy constructor =======\n");
		ScavTrap a("SpongeBob");
		ScavTrap b(a);
	}
	// Assignment Constructor
	{
		std::cout << cyn("==== Test[3]: assignment constructor ====\n");
		ScavTrap gary("Gary");
		ScavTrap mrKrabs("Mr. Krabs");

		mrKrabs = gary;
	}

}
