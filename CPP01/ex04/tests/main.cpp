/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:43:32 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:43:51 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

/**
 * @brief Runs all unit tests for the replace program.
 *
 * Prints a header, executes each test suite, and prints a summary.
 * The program returns 0 implicitly, and reports any failures.
 *
 * @return int Exit status (always 0 in this implementation).
 */
int	main(void)
{
	
    std::cout << YEL << "=======================================\n"
					 << "         Running all unit tests\n"
					 << "=======================================\n"
					 << RESET;
	
	int	totalFailures = 0;
	int	totalTestSuites = 0;

	totalTestSuites++;
	totalFailures += replaceLineTest();
	
	totalTestSuites++;
	totalFailures += replaceFileTest();


	std::cout << YEL "============= Test summary ============" RESET << '\n'
			  << WHT "Total test suits: " << totalTestSuites << RESET << '\n'
			  << RED "total failures: " << totalFailures << RESET << '\n';
	std::cout << YEL "=======================================\n" RESET;
	if (totalFailures == 0)
		std::cout << GRN "ALL TESTS PASSED!\n" RESET;
}
