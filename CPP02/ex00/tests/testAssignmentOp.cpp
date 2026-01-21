/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testAssignmentOp.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:02:25 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/20 23:08:31 by diade-so         ###   ########.fr       */
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
int	testAssignmentOp(void)
{
	int passed = 0;
	int failed = 0;
	int numTests = 1;

	std::cout << YEL("==== Running test for AssignmentOp ====\n");
	std::cout << BLU("Copy assignment operator test\n");

	Fixed a;
	Fixed b;

	a.setRawBits(84);
	b = a; // calls operator=

	if (b.getRawBits() == 84)
	{
		std::cout << GRN("TEST PASSED\n");
		passed++;
	}
	else
	{
		std::cout << RED("TEST FAILED\n");
		failed++;
	}
	std::cout << '\n';

	std::cout << BLU("========= AssignmentOp summary ========\n")
			  << GRN("Tests passed: ") << passed << '\n'
			  << RED("Tests failed: ") << failed << '\n'
			  << "Total tests: " << numTests << '\n';	
	if (failed == 0)
		std::cout << GRN("All tests passed!\n");

	std::cout << BLU("=======================================\n")
			  << YEL("=============END UNIT TEST=============\n");
	return (failed);
}
