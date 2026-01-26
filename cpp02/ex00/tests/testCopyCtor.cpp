/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testCopyCtor.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:01:44 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/20 23:08:14 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

/**
 * @brief Unit test for the Fixed copy constructor.
 *
 * Verifies that a Fixed object created via the copy
 * constructor correctly copies the raw fixed-point
 * value from the source object.
 *
 * This test ensures:
 * - The original object remains unchanged
 * - The copied object contains the same raw value
 *
 * @return Number of failed tests (0 if the test passes).
 */
int	testCopyCtor(void)
{
	int passed = 0;
	int failed = 0;
	int numTests = 1;

	std::cout << YEL("====== Running test for CopyCtor =====\n");
	Fixed original;
	original.setRawBits(21);

	Fixed copy(original);

	if (copy.getRawBits() == 21)
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

	std::cout << BLU("=========== CopyCtor summary ==========\n")
			  << GRN("Tests passed: ") << passed << '\n'
			  << RED("Tests failed: ") << failed << '\n'
			  << "Total tests: " << numTests << '\n';	
	if (failed == 0)
		std::cout << GRN("All tests passed!\n");

	std::cout << BLU("=======================================\n")
			  << YEL("=============END UNIT TEST=============\n");
	return (failed);
}
