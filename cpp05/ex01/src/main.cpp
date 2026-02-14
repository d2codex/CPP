#include "Form.hpp"
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
	
	// Successful signing
    printTestName("Successful signing");
	try
    {
        Form tax1("W-2", 30, 120);
		std::cout << tax1 << '\n';
        Bureaucrat bob1("Bob", 25); // high enough grade
		std::cout << bob1 << '\n';

        bob1.signForm(tax1);
    }
    catch (std::exception& e)
    {
        LOG_ERROR() << e.what();
    }

    // Signing fails: grade too low
    printTestName("Signing fails: grade too low");
    try
    {
        Form tax2("W-2", 30, 120);
		std::cout << tax2 << '\n';
        Bureaucrat bob2("Bob", 45); // grade too low
		std::cout << bob2 << '\n';
        bob2.signForm(tax2);
    }
    catch (std::exception& e)
    {
        LOG_ERROR() << e.what();
    }

	 // Form instantiation fails: grade too high
    printTestName("Form Instantiation fails: form grade too high");
    try
    {
        Form tax2("W-2", 0, 120);
        Bureaucrat bob2("Bob", 2); // grade too low
        bob2.signForm(tax2);
    }
    catch (std::exception& e)
    {
        LOG_ERROR() << e.what();
    }
    // Signing fails: form already signed
    printTestName("Signing fails: form already signed");
    try
    {
        Form tax3("W-2", 30, 120);
        Bureaucrat alice("Alice", 20); // can sign
        Bureaucrat charlie("Charlie", 10); // also can sign

        alice.signForm(tax3);  // first signs successfully
        charlie.signForm(tax3); // should throw FormAlreadySigned
    }
    catch (std::exception& e)
    {
        LOG_ERROR() << e.what();
    }
}
