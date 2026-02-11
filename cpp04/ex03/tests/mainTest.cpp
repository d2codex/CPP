/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 02:21:11 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 02:21:14 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

int	main(void)
{
	logLevel level = NONE;
	Logger::get().setThreshold(level);
    std::cout << yel("=======================================\n"
					 "         Running all unit tests\n"
					 "=======================================\n");
	
	int	totalFailures = 0;
	int	totalTestSuites = 0;

	totalTestSuites++;
	totalFailures += iceTest();
	
	totalTestSuites++;
	totalFailures += cureTest();

	totalTestSuites++;
	totalFailures += characterTest();

	std::cout << blu("Test Suites Summary\n")
			  << wht("Total test suits: ") << totalTestSuites << '\n'
			  << red("total failures: ") << totalFailures << '\n'
			  << yel("=======================================\n");
	if (totalFailures == 0)
		std::cout << grn("ALL TESTS PASSED!\n");
}
