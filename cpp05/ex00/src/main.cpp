#include "Bureaucrat.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

bool initLogger(int argc, char **argv)
{
	if (argc == 1)
	{
		Logger::get().setThreshold(NONE);
		return (true);
	}
	if (argc == 2)
	{
		logLevel level = Logger::stringToLevel(argv[1]);
		if (level == INVALID)
		{
			std::cout << red("Error. invalid log level\n");
			std::cout << cyn("usage: ./bin/<program_name> [log level]\n");
			std::cout << cyn("log levels: info warning error\n");
			return (false);
		}
		#ifndef DBUG
		if (level == DEBUG)
		{
			std::cout << mag("Warning: DEBUG messages are not enabled in this build.\n");
			Logger::get().setThreshold(INFO); // fallback threshold
			return (true);
		}
		#endif
		Logger::get().setThreshold(level);
		return (true);
	}
	std::cout << cyn("usage: ./bin/<program_name> [log level]\n");
	std::cout << cyn("log levels: info warning error\n");
	return (false);
}

void printTestName(const std::string& testName)
{
	std::cout << yel("======================================================\n");
	std::cout << YEL << "Testing " << testName << RESET << '\n';
}


int	main(int argc, char **argv)
{
	if (!initLogger(argc, argv))
		return (1);
try
    {
        // create Bureaucrats
        Bureaucrat bob("SpongeBob", 45);
        Bureaucrat gary("Gary", 1);
        Bureaucrat plankton("Plankton", 148);

        // test overload << 
        std::cout << bob << '\n';
        std::cout << gary << '\n';
        std::cout << plankton << '\n';

        // test increment/decrement
        bob.incrementGrade();
        bob.incrementGrade();
        bob.incrementGrade();
        std::cout << "After incrementing Spongebob: " << bob << '\n';

        plankton.decrementGrade();
        plankton.decrementGrade();
        std::cout << "After decrementing Plankton: " << plankton << '\n';

        // throw exceptions
        gary.incrementGrade();     // Already at max (1)
        plankton.decrementGrade();  // Already at min (150)
    }
catch (const std::exception& e)
    {
        std::cerr << RED << "Exception caught: " << e.what() << '\n' << RESET;
    }
}
