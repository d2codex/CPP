/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:35:11 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:35:13 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Weapon.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>

/**
 * @brief Runs all unit test suites and prints a summary.
 *
 * Calls each test function, accumulates total failures, and
 * reports the overall result.
 *
 * @return 0 if all tests pass, otherwise number of failures.
 */
int	main(void)
{
	
    std::cout << YEL << "=======================================\n"
					 << "         Running all unit tests\n"
					 << "=======================================\n";
	
	int	totalFailures = 0;
	int	totalTestSuites = 0;

	totalTestSuites++;
	totalFailures += weaponTest();

	totalTestSuites++;
	totalFailures += humanATest();

	totalTestSuites++;
	totalFailures += humanBWeaponTest();

	totalTestSuites++;
	totalFailures += humanBNoWeaponTest();

	std::cout << YEL "============= Test summary ============" RESET << '\n'
			  << WHT "Total test suits: " << totalTestSuites << RESET << '\n'
			  << RED "total failures: " << totalFailures << RESET << '\n';
	std::cout << YEL "=======================================\n" RESET;
	if (totalFailures == 0)
		std::cout << GRN "ALL TESTS PASSED!\n" RESET;
}
