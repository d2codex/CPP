/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testAssignmentCtor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:02:25 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/20 23:03:21 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

/**
 * @brief Unit test for the Fixed copy assignment operator.
 *
 * Verifies that assigning one Fixed object to another
 * using the '=' operator correctly copies the raw
 * fixed-point value.
 *
 * This test ensures:
 * - operator= is invoked
 * - The destination object receives the source value
 *
 * @return Number of failed tests (0 if the test passes).
 */
int	testAssignmentCtor(void)
{
	int passed = 0;
	int failed = 0;
	int numTests = 1;

	std::cout << YEL "=== Running test for AssignmentCtor ===\n" RESET;
	std::cout << BLU "Copy assignment operator test\n" RESET;

	Fixed a;
	Fixed b;

	a.setRawBits(84);
	b = a; // calls operator=

	if (b.getRawBits() == 84)
	{
		std::cout << GRN "TEST PASSED\n" RESET;
		passed++;
	}
	else
	{
		std::cout << RED "TEST FAILED\n" RESET;
		failed++;
	}
	std::cout << '\n';

	std::cout << BLU "======== AssignmentCtor summary =======\n" RESET
			  << GRN "Tests passed: " << passed << RESET << '\n'
			  << RED "Tests failed: " << failed << RESET << '\n'
			  << "Total tests: " << numTests << '\n';	
	if (failed == 0)
		std::cout << GRN "All tests passed!\n" RESET;

	std::cout << BLU "=======================================\n" RESET;
	std::cout << YEL "=============END UNIT TEST=============\n" RESET;
	return (failed);
}
