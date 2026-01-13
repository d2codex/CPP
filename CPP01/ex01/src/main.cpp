/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:01:41 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/13 18:01:43 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "colors.hpp"
#include <iostream>
#include <cstddef>

/**
 * @brief Defines a test case for zombieHorde().
 *
 * Stores input parameters and the expected outcome for a single
 * test execution.
 */
struct testCases
{
	const char* description;
	const char*	name;
	int			N;
	bool		expectPass;
};

/**
 * @brief Entry point for zombieHorde() tests.
 *
 * Executes a set of predefined test cases to validate correct
 * behavior, boundary handling, and error rejection. In DEBUG
 * mode, construction and destruction counters are reset between
 * tests for accurate diagnostics.
 */
int	main(void)
{

	testCases test[] = {
		{"Normal case: N = 5", "SpongeBob Squarepants", 5, true},
		{"N is negative", "Patrick", -125, false},
		{"N is Zero", "Squidward", 0,  false},
		{"N is MAX_HORDE_SIZE (1,000,000)", "Plankton", 1000000, true},
		{"N is greater than MAX_HORDE_SIZE", "Gary", 1000001, false}
	};

	for (size_t i = 0; i < sizeof(test) / sizeof(test[0]); i++)
	{
		DBUG(Zombie::resetCounters();)
		std::cout << YEL "=== Test: " << test[i].description << " ===\n" RESET;
		
		Zombie* horde = zombieHorde(test[i].N, test[i].name);
		bool gotPointer = (horde != NULL);
		bool expected = test[i].expectPass;
		if (gotPointer == expected)
		{
			if (horde)
			{
				std::cout << CYN "Test Passed (horde created)\n" RESET;
				if (test[i].N <= DISPLAY_LIMIT)
				{
					for (int j = 0; j < test[i].N; j++)
						horde[j].announce();
				}
				else
				{
					std::cout << "First: ";
					horde[0].announce();
					std::cout << "  ... (" << test[i].N << " zombies total)\n";
				}
			}
			else
				std::cout << GRN "Test Passed (invalid rejected)\n" RESET;
		}
		else
			std::cout << RED "Test failed\n" RESET;
		delete[] (horde);
	}
}
