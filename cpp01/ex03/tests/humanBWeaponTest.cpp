/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanBWeaponTest.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:31:09 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:34:40 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "colors.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>
#include <sstream>

/**
 * @struct HumanBTest
 * @brief Holds data for one HumanB unit test.
 */
struct HumanBTest
{
	std::string description;
	std::string name;
	std::string weaponType;
	std::string expectedOutput;
	bool		shouldThrow;
};

/**
 * @brief Runs unit tests for HumanB with a weapon set.
 * @return Number of failed tests.
 */
int	humanBWeaponTest()
{
	int passed = 0;
	int failed = 0;

	HumanBTest test[] = {
		{
			"Valid Normal case",
			"SpongeBob",
			"hammerhead",
			"SpongeBob attacks with their hammerhead\n",
			false
		},
		{
			"Invalid Empty name",
			"",
			"club",
			"",
			true
		},
		{
			"Invalid Whatspaces only name",
			"			  ",
			"club",
			"",
			true
		},
		{
			"Valid complex name",
			"Sponge Bob Square Pants",
			"stingray",
			"Sponge Bob Square Pants attacks with their stingray\n",
			false
		},
		{
			"Valid special characters name",
			"aafk;af12",
			"starfish",
			"aafk;af12 attacks with their starfish\n",
			false
		},
		{
			"Valid spaces before and after name",
			"	Squidward ",
			"club",
			"	Squidward  attacks with their club\n",
			false
		},
	};

	std::cout << YEL "==Running test for humanB class w/ weapon==\n" RESET;
	size_t numTests = sizeof(test) / sizeof(test[0]);
	for (size_t i = 0; i < numTests; i++)
	{
		try
		{
			std::cout << BLU "Test[" << i << "] " RESET
					  << test[i].description << '\n';
			Weapon weapon(test[i].weaponType);
			HumanB human(test[i].name);
			human.setWeapon(weapon);
			// redirect std::cout to a string buffer,
			// run the function, then restore it.
			std::streambuf* oldCout = std::cout.rdbuf();   // save original
			std::ostringstream buffer;              //declare buffer stream
			std::cout.rdbuf(buffer.rdbuf());               // redirect
			human.attack();                               // run the function
			std::cout.rdbuf(oldCout);                      // restore
			std::string output = buffer.str();             // captured output

			std::cout << "Name Input:   " << test[i].name << '\n'
					  << "Weapon Input: " << test[i].weaponType << '\n'
					  << "Expected:     " << test[i].expectedOutput
					  << "Result:       " << output;

			if (test[i].shouldThrow)
			{
				std::cout << RED "TEST FAIL (expected throw)\n" RESET;
				failed++;
			}
			else if (output == test[i].expectedOutput)
			{
				std::cout << GRN "TEST SUCCESS\n" RESET;
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
			std::cerr << RED "Error: " << e.what() << RESET << '\n';
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
	std::cout << BLU "======= humanBWeaponTest summary ======" RESET << '\n'
			  << GRN "Tests passed: " << passed << RESET << '\n'
			  << RED "Tests failed: " << failed << RESET << '\n'
			  << "Total tests: " << numTests << '\n';	
	if (failed == 0)
		std::cout << GRN "All tests passed!\n" RESET;

	std::cout << BLU "=======================================\n" RESET;
	std::cout << YEL "=============END UNIT TEST=============\n" RESET;
	return (failed);
}
