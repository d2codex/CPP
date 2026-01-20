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
	
    std::cout << YEL << "=======================================\n"
					 << "         Running all unit tests\n"
					 << "=======================================\n"
					 << RESET;
	
	int	totalFailures = 0;
	int	totalTestSuites = 0;

	totalTestSuites++;
	totalFailures += testDefaultCtor();
	
	totalTestSuites++;
	totalFailures += testCopyCtor();

	totalTestSuites++;
	totalFailures += testAssignmentOp();


	std::cout << YEL "============= Test summary ============" RESET << '\n'
			  << WHT "Total test suits: " << totalTestSuites << RESET << '\n'
			  << RED "total failures: " << totalFailures << RESET << '\n';
	std::cout << YEL "=======================================\n" RESET;
	if (totalFailures == 0)
		std::cout << GRN "ALL TESTS PASSED!\n" RESET;
}
