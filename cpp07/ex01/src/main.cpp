#include "Iter.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <iomanip>
#include <ostream>

struct Point
{
	int x;
	int y;
};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p.x << ", " << p.y << ")";
	return (os);
}

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

template<typename T>
void	print(const T& x)
{
	std::cout << x << " ";
}

template<typename T>
void increment(T& x)
{
	x++;
}

int	main(int argc, char **argv)
{

	if (!initLogger(argc, argv))
		return (1);

	// const array support type int
	{
		printTestName("const array support type int");
		const int array[] = {1, 2, 3};
		iter(array, 3, print<int>);
		std::cout << std::endl;
	}
	// const array support type float
	{
		printTestName("const array support type float");
		std::cout << std::setprecision(7);
		const float array[] = {1.0123456f, 2.0123456f, 3.0123456f};
		iter(array, 3, print<float>);
		std::cout << std::endl;
	}
	// const array suport type char
	{
		printTestName("const array support type char");
		const char array[] = {'a', 'b', 'c'};
		iter(array, 3, print<char>);

		std::cout << std::endl;
	}
	// const array suport type std::string
	{
		printTestName("const array support type std::string");
		const std::string array[] = {"hello", "world", "!"};
		iter(array, 3, print<std::string>);

		std::cout << std::endl;
	}

	// modification test
	// confirms passing elements correctly by reference (not copies)
	// function can mutate data
	{
		printTestName("non-const int array modification");
		int array[] = {1, 2, 3};
		
		std::cout << "before modification: ";
		iter(array, 3, print<int>);
		std::cout << std::endl;
		
		std::cout << "after modification:  ";
		iter(array, 3, increment<int>);
		iter(array, 3, print<int>);
		std::cout << std::endl;
	}
	// non-const char modification
	{
		printTestName("non-const char array modification");
		char array[] = {97, 98, 99};
		
		std::cout << "before modification: ";
		iter(array, 3, print<char>);
		std::cout << std::endl;
		
		iter(array, 3, increment<char>);
		std::cout << "after modification:  ";
		iter(array, 3, print<char>);
		std::cout << std::endl;
	}

	// custom struct Point const array
	{
		printTestName("const array support type Point");
		const Point array[] = { {1, 2}, {3, 4}, {5, 6} };
		iter(array, 3, print<Point>);
		std::cout << std::endl;
	}
	// custom struct Point non-const array
	{
		printTestName("non-const array support type Point");
		Point array[] = { {1, 2}, {3, 4}, {5, 6} };
		iter(array, 3, print<Point>);
		std::cout << std::endl;
	}
	
	// test NULL pointer
	{
		printTestName("Null pointer - should return, does nothing");
		iter<int>(NULL, 3, print<int>);
		LOG_INFO() << "Pointer is null, function returns";
	}
		// test N = 0
	// should not crash
	// should not call function
	{
		printTestName("N = 0");
		int array[] = {1, 2, 3};
		iter(array, 0, print<int>);
		LOG_INFO() << "N is 0, function not called";
	}
	// single element - catches off by one errors
	{
		printTestName("N is wrong size");
		int oneElement[] = {42};
		iter(oneElement, 2, print<int>);
		std::cout << std::endl;
		LOG_INFO() << "N invalid, exhibits undefined behavior";
	}
}
