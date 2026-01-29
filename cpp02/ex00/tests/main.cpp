/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:01:11 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/20 23:05:35 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "tests.hpp"
#include "Logger.hpp"
#include <iostream>

int	main(void)
{
	Logger::setThreshold(Logger::NONE);
	
    std::cout << yel("=======================================\n"
					 "         Running all unit tests\n"
					 "=======================================\n");
	
	int	totalFailures = 0;
	int	totalTestSuites = 0;

	totalTestSuites++;
	totalFailures += testSetGetRawBits();
	
	totalTestSuites++;
	totalFailures += testCopyCtor();

	totalTestSuites++;
	totalFailures += testAssignmentOp();


	std::cout << yel("============= Test summary ============\n")
			  << wht("Total test suits: ") << totalTestSuites << '\n'
			  << red("total failures: ") << totalFailures << '\n'
			  << yel("=======================================\n");
	if (totalFailures == 0)
		std::cout << grn("ALL TESTS PASSED!\n");
}
