#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

bool initLogger(int argc, char **argv)
{
	if (argc == 1)
	{
		Logger::get().setThreshold(ERROR);
		return (true);
	}
	if (argc == 2)
	{
		logLevel level = Logger::stringToLevel(argv[1]);
		if (level == INVALID)
		{
			std::cout << red("Error. invalid log level\n");
			std::cout << cyn("usage: ./bin/<program_name> [log level]\n");
			std::cout << cyn("log levels: debug(debug build only) info warning\n");
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
	std::cout << cyn("log levels: debug(debug build only) info warning\n");
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

	// Test Shrubbery success
	{
		printTestName("Shrubbery");
		try
		{
		ShrubberyCreationForm test("home");
		std::cout << test << '\n';

		Bureaucrat squidward("Squidward", 11);
		std::cout << squidward << '\n';

		squidward.signForm(test);
		//squidward.signForm(test);
		squidward.executeForm(test);
		}
		catch (std::exception& e)
		{
			LOG_ERROR() << e.what();
		}
	}

	// Drill 50/50
	{
		printTestName("Robotomy");
		int i = 0;
		while (i < 3)
		{
			try
			{
				RobotomyRequestForm drill("drill");
				std::cout << drill << '\n';

				Bureaucrat bob("bob", 35);
				std::cout << bob << '\n';

				bob.signForm(drill);
				bob.executeForm(drill);
			}
			catch (std::exception& e)
			{
				LOG_ERROR() << e.what();
			}
			i++;
		}
	}
	// presidential pardon request
	{
		printTestName("Pardon");
		try
		{
			PresidentialPardonForm form("SpongeBob");
			std::cout << form << '\n';

			Bureaucrat bob("bob", 2);
			std::cout << bob << '\n';

			bob.signForm(form);
			bob.executeForm(form);
		}
		catch (std::exception& e)
		{
			LOG_ERROR() << e.what();
		}
	}

}
