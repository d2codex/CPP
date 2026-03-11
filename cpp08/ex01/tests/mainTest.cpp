/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:09:28 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/11 09:09:29 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

int	main(void)
{
	Logger::logLevel level = Logger::NONE;

	Logger::get().setThreshold(level);
	LOG_DEBUG() << "test";
    std::cout << yel("=======================================\n"
					 "         Running all unit tests\n"
					 "=======================================\n");
	
	int	totalFailures = 0;
	int	totalTestSuites = 0;

	totalTestSuites++;
	totalFailures += testParamCtor();

	totalTestSuites++;
	totalFailures += testCopyCtor();

	totalTestSuites++;
	totalFailures += testAssignment();

	totalTestSuites++;
	totalFailures += testShortestSpan();

	totalTestSuites++;
	totalFailures += testLongestSpan();

	totalTestSuites++;
	totalFailures += testAddNumber();

		std::cout << blu("Test Suites Summary\n")
			  << wht("Total test suits: ") << totalTestSuites << '\n'
			  << red("total failures: ") << totalFailures << '\n'
			  << yel("=======================================\n");
	if (totalFailures == 0)
		std::cout << grn("ALL TESTS PASSED!\n");
}
