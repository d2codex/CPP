#include "Array.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <iomanip>
#include <ostream>

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
	printTestName("Demos");
	// int allocation on the heap
	{
		printTestName("int heap allocation");
		int* a = new int();
		std::cout << "int value: " << *a << std::endl;
		delete a;
/*
		// without () we get unitialized values and will have garbage values
 		// thats why its safter to do _array(new T[n]()) for the 
 		// parameterized constructor
		int* b = new int;
		std::cout << "b value: " << *b << std::endl;
		delete b;
*/
	}
	// array object heap allocation
	// must specify type for function templates
	{
		printTestName("array object heap allocation");
		Array<int>* b = new Array<int>();
		std::cout << "array contents b: \n" << *b;
		delete b;
	}
	// default ctor
	{
		printTestName("array object stack allocation");
		Array<int> a;
		std::cout << "array contents a: \n" << a;
	}
	// integration test
	{
		printTestName("integration test");
		Array<std::string> a(3);
		a[0] = "hello";
		a[1] = "Spongebob";
		a[2] = "!";

		std::cout << "array contents a: \n" << a;
		Array<std::string> b;
		std::cout << "array contents b: \n" << b;

		b = a;
		
		Array<std::string> c(a);
		std::cout << "array contents c: \n" << c;
		
		try
		{
			b[3];
		}
		catch (std::exception& e)
		{
			LOG_ERROR() << e.what();
		}
	}
}
