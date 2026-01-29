/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testDefaultCtor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:01:06 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/20 23:01:09 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

/**
 * @brief Test case for Fixed raw bit values.
 *
 * Holds a description and a raw integer value used to
 * validate getRawBits() and setRawBits().
 */
struct FixedRawTests
{
	std::string desc;
	int			raw;
};

/**
 * @brief Unit tests for the Fixed default constructor.
 *
 * Verifies that a Fixed object correctly stores and
 * returns raw values after initialization.
 *
 * Each test:
 * - Creates a Fixed instance
 * - Sets raw bits manually
 * - Confirms getRawBits() returns the expected value
 *
 * @return Number of failed tests (0 if all tests pass).
 */
int	testSetGetRawBits(void)
{
	FixedRawTests test[] = {
		{"Default raw bits", 0},
		{"Positive raw bits", 42},
		{"Negative raw bits", -42},
		{"Large raw bits", 123456},
		{"Very Larg raw bits", 1234567890},
	};

	int passed = 0;
	int failed = 0;

	std::cout << yel("==== Running test for SetGetRawBits ===\n");
	size_t	numTests = sizeof(test) / sizeof(test[0]);
	for (size_t i = 0; i < numTests; i++)
	{
		FixedRawTests& t = test[i];
		std::cout << BLU << "Test[" << i << "] " << RESET << t.desc << '\n';
		
		Fixed a;
		a.setRawBits(t.raw);

		int result = a.getRawBits();
		std::cout << "Input:  " << t.raw << '\n';
		std::cout << "Result: " << result << '\n';

		if (result == t.raw)
		{
			std::cout << grn("TEST PASSED\n");
			passed++;
		}
		else
		{
			std::cout << red("TEST FAILED\n");
			failed++;
		}
		std::cout << '\n';
	}
	
	std::cout << blu("======== SetGetRawBits summary ========\n")
			  << grn("Tests passed: ") << passed << '\n'
			  << red("Tests failed: ") << failed << '\n'
			  << "Total tests: " << numTests << '\n';	
	if (failed == 0)
		std::cout << grn("All tests passed!\n");

	std::cout << blu("=======================================\n")
			  << yel("=============END UNIT TEST=============\n");
	return (failed);
}
