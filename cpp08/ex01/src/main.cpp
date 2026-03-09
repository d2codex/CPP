#include "Span.hpp"
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



int	main(int argc, char **argv)
{

	if (!initLogger(argc, argv))
		return (1);
	
	Span a(20);
	Span b(a);
	Span c(0);

	b.addNumber(5);
	b.addNumber(-3);
	b.addNumber(29);

	try
	{
		c.addNumber(1);
	}
	catch (Span::SpanFullException& e)
	{
		LOG_ERROR() << e.what();
	}
}
