#include "Span.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <climits>

bool initLogger(int argc, char **argv)
{
	if (argc == 1)
	{
		Logger::get().setThreshold(Logger::ERROR);
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
	// demo 1
	{
		printTestName("copy");
		Span a(3);
		Span b(a);

		b.addNumber(5);
		b.addNumber(-3);
		b.addNumber(29);

		b.printVector();
		// add number when full should throw
		try
		{
			b.addNumber(928);
		}
		catch (Span::SpanFullException& e)
		{
			LOG_ERROR() << e.what();
		}
	}
	// demo 2
	{
		printTestName("assign");
		Span a(3);
		Span b(0);
		// add number when size is 0
		try
		{
			b.addNumber(1);
		}
		catch (Span::SpanFullException& e)
		{
			LOG_ERROR() << e.what();
		}

		b = a;
		b.addNumber(1);
		b.printVector();
	}
		// longestSpan
	{
		printTestName("longestSpan - difference fits in unsigned int");
		Span a(3);

		a.addNumber(INT_MIN);
		a.addNumber(1000);
		a.addNumber(INT_MAX);

		a.printVector();
		a.longestSpan();
	}
	// longestSpan - throws
	{
		printTestName("longestSpan - not enough numbers");
		Span a(3);
		try
		{
			a.addNumber(1);
			a.printVector();
			a.longestSpan();	
		}
		catch(Span::NoSpanException& e)
		{
			LOG_ERROR() << e.what();
		}
	}
	//shortest Span fits in unsigned int
	{
		printTestName("shortestSpan - difference fits in unsigned int");
		Span a(2);

		a.addNumber(INT_MIN);
		a.addNumber(INT_MAX);

		a.shortestSpan();
		a.printVector();
	}
	//shortest Span fits in unsigned int
	{
		printTestName("shortestSpan - difference fits in unsigned int");
		Span a(4);

		a.addNumber(1);
		a.addNumber(1);
		a.addNumber(1);
		a.addNumber(1);

		a.shortestSpan();
		a.printVector();
	}
}
