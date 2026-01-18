/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weaponTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:36:32 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:36:34 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "colors.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

/**
 * @struct WeaponTest
 * @brief Holds input and expected outcome for a weapon test.
 */
struct WeaponTest
{
	std::string description;
	std::string typeValue;
	bool		shouldThrow;
};

/**
 * @brief Runs the unit tests for the Weapon class.
 *
 * Iterates through predefined test cases, verifies expected
 * behavior, and prints pass/fail results.
 *
 * @return Number of failed tests.
 */
int weaponTest()
{
	int	passed = 0;
	int failed = 0;

	WeaponTest test[] = {
		{"Valid Normal case", "club", false},
		{"Invalid Empty type", "", true},
		{"Invalid White spaces only", "		 ", true},
		{"Valid complex type", "Crude Spiked Club", false},
		{"Valid special characters", "afkl;j1234#$@", false},
		{"Valid spaces before and after", " swordfish  ", false}
	};
	std::cout << YEL "==== Running test for weapon class ====\n" RESET;
	size_t numTests = sizeof(test) / sizeof(test[0]);
	for (size_t i = 0; i < numTests; i++)
	{
		std::cout << BLU "Test[" << i << "] " RESET << test[i].description <<'\n';

		try
		{
			Weapon weapon(test[i].typeValue);
			std::string result = weapon.getType();
			std::cout << "Input:  " << test[i].typeValue << '\n'
					  << "Result: " << result << '\n';

			if (test[i].shouldThrow)
			{
				std::cout << RED "TEST FAIL (expected throw)\n" RESET;
				failed++;
			}
			else if (test[i].typeValue == result)
			{
				std::cout << GRN "TEST PASSED\n" RESET;
				passed++;
			}
			else
			{
				std::cout << RED "TEST FAIL (output mismatch)\n" RESET;
				failed++;
			}

		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Error:    " << e.what() << RESET << '\n';
			if (test[i].shouldThrow)
			{
				std::cout << "Expected: " << e.what() << '\n';
				std::cout << GRN "TEST SUCCESS\n" RESET;
				passed++;
			}
			else
			{
				std::cout << "Expected: " << e.what() << '\n';
				std::cout << RED "TEST FAIL\n" RESET;
				failed++;
			}
		}
		std::cout << '\n';
	}

	std::cout << BLU "========== weaponTest summary =========" RESET << '\n'
			  << GRN "Tests passed: " << passed << RESET << '\n'
			  << RED "Tests failed: " << failed << RESET << '\n'
			  << "Total tests: " << numTests << '\n';	
	if (failed == 0)
		std::cout << GRN "All tests passed!\n" RESET;

	std::cout << BLU "=======================================\n" RESET;
	std::cout << YEL "=============END UNIT TEST=============\n" RESET;
	return (failed);
}
