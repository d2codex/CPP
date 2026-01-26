/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHordeTest.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 22:53:19 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/24 23:59:28 by diade-so         ###   ########.fr       */
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

int	zombieHordeTest(void)
{
	testCases test[] = {
		{"Normal case: N = 5", "SpongeBob Squarepants", 5, true},
		{"Minimum case: N = 1", "Squidward", 1,  true},
		{"N is MAX_HORDE_SIZE (1,000,000)", "Plankton", 1000000, true},
	};
	
	std::cout << YEL "==== Running test for zombieHorde ====\n" RESET;
	int passed = 0;
	int failed = 0;
	size_t numTests = sizeof(test) / sizeof(test[0]);
	for (size_t i = 0; i < numTests; i++)
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
				std::cout << CYN "TEST SUCCESS (horde created)\n" RESET;
				if (horde[0].getName() ==test[i].name)
					std::cout << GRN "Name assigned correctly\n" RESET;
				else
					std::cout << RED "NAME assignment failed\n" RESET;

				if (test[i].N <= DISPLAY_LIMIT)
				{
					for (int j = 0; j < test[i].N; j++)
					{
						std::cout << "[" << j + 1 << "] ";
						horde[j].announce();
					}
				}
				else
				{
					std::cout << "First: ";
					horde[0].announce();
					std::cout << "  ... (" << test[i].N << " zombies total)\n";
				}
			}
			else
				std::cout << GRN "TEST SUCCESS (invalid rejected)\n" RESET;
			passed++;
		}
		else
		{
			std::cout << RED "TEST FAILED\n" RESET;
			failed++;
		}
		delete[] (horde);
	}

	std::cout << BLU "========= zombieHorde summary =========" RESET << '\n'
			  << GRN "Tests passed: " << passed << RESET << '\n'
			  << RED "Tests failed: " << failed << RESET << '\n'
			  << "Total tests: " << numTests << '\n';	
	if (failed == 0)
		std::cout << GRN "All tests passed!\n" RESET;
	std::cout << BLU "=======================================\n" RESET;
	std::cout << YEL "=============END UNIT TEST=============\n" RESET;
	return (failed);

}
