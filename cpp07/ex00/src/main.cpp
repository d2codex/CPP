#include "whatever.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

bool initLogger(int argc, char **argv)
{
	if (argc == 1)
	{
		Logger::get().setThreshold(Logger::NONE);
		return (true);
	}
	if (argc == 2)
	{
		Logger::logLevel level = Logger::stringToLevel(argv[1]);
		if (level == Logger::INVALID)
		{
			std::cout << red("Error. invalid log level\n");
			std::cout << cyn("usage: ./bin/<program_name> [log level]\n");
			std::cout << cyn("log levels: debug info warning error\n");
			return (false);
		}
		Logger::get().setThreshold(level);
		return (true);
	}
	std::cout << cyn("usage: ./bin/<program_name> [log level]\n");
	std::cout << cyn("log levels: debug info warning error\n");
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

	//subject test
	{
		printTestName("subject test");
		int a = 2;
		int b = 3;

		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		
		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	// demo test ints swap
	{
		int a = 2;
		int b = 3;

		printTestName("swap int (2,3)");
		::swap(a, b);
	}
	// demo test int min / max
	{
		int a = 2;
		int b = 3;

		printTestName("max int (2, 3)");
		::max(a , b);

		printTestName("min int (2, 3)");
		::min(a , b);
	}
	// demo test strings
	{
		std::string s1 = "hello";
		std::string s2 = "world";

		printTestName("swap std::string (hello, world)");
		::swap(s1, s2);
	}
	// demo test int equals returns second 
	{
		int a = 2;
		int b = 2;

		printTestName("min equal (2, 2), second is returned");
		::min(a, b);

		printTestName("max equal (2, 2), second is returned");
		::max(a, b);
	}
	

}
