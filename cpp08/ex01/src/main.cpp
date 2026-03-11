/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 08:42:20 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/11 08:47:18 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <climits>
#include <list>

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

	srand(time(NULL));

	// demo 1 - copy
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
	// demo 2 - assign
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
		printTestName("shortestSpan - smallest difference");
		Span a(4);

		a.addNumber(1);
		a.addNumber(1);
		a.addNumber(1);
		a.addNumber(1);

		a.shortestSpan();
		a.printVector();
	}
	// add multiple numbers 5
	{
		printTestName("add multiple numbers - 5");
		std::vector<int> numbers = generateRandomNumbers< std::vector<int> >(5);
	
		Span a(5);
		a.addNumber(numbers.begin(), numbers.end());
		a.printVector();
		a.shortestSpan();
		a.longestSpan();
	}
	// add multiple numbers from list container
	{
		printTestName("add multiple numbers from list container");
		std::list<int> numbers = generateRandomNumbers< std::list<int> >(5);
	
		Span a(5);
		a.addNumber(numbers.begin(), numbers.end());
		a.printVector();
		a.shortestSpan();
		a.longestSpan();
	}
/*
	// add multiple numbers 2000000
	{
		printTestName("add multiple numbers - 2000000");
		std::vector<int> numbers = generateRandomNumbers< std::vector<int> >(2000000);
	
		Span a(2000000);
		a.addNumber(numbers.begin(), numbers.end());
		a.shortestSpan();
		a.longestSpan();
	}
*/
}
