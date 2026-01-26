/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceLineTest.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:45:24 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:45:42 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include "tests.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>
#include <fstream>

struct LineTestCase
{
	std::string desc;
	std::string line;
	std::string expected;
	std::string	s1;
	std::string s2;
};

/**
 * @brief Unit tests for replaceLine().
 *
 * This function tests replaceLine() using a set of predefined test cases.
 * The tests assume valid input: s1 must not be empty (this is validated in main()).
 *
 * @note replaceLine() is a low-level helper and does not perform input validation.
 *       Any invalid input (e.g., empty s1) is handled by the caller, not tested here.
 *
 * @return int Number of failed tests (0 if all tests passed).
 */
int	replaceLineTest()
{
	int passed = 0;
	int failed = 0;

	LineTestCase test[] = {
		// Normal
		{
			"Valid normal case",
			"hallo", "hbllo",
			"a", "b"
		},
		// No match (should still pass, just no change)
		{
			"No match case",
			"hello", "hello",
			"x", "y"
		},
		// Replace with longer string
		{
			"Replace with longer string",
			"hello", "heyyyo",
			"ll", "yyy"
		},
		// Replace with shorter string
		{
			"Replace with shorter string",
			"hello", "heo",
			"ll", ""
		},
		// Replace with empty line (still valid if s1 is not empty)
		{
			"Valid empty line",
			"", "",
			"a", "b"
		},
		// Replace with whitespace (space)
		{
			"Replace space",
			"a b c", "a-X-b-X-c",
			" ", "-X-"
		},
		// Replace with tab
		{
			"Replace tab",
			"a\tb\tc", "a-X-b-X-c",
			"\t", "-X-"
		},
		// Replace with special characters
		{
			"Replace special chars",
			"hello!world!", "hello?world?",
			"!", "?"
		},
		// Multiple occurrences
		{
			"Multiple occurrences",
			"aaaa", "bbbb",
			"a", "b"
		},
		// Overlapping pattern case (important!)
		// Example: replace "aa" in "aaaa" -> should become "bb" if handled correctly
		{
			"Overlapping pattern",
			"aaaa", "bb",
			"aa", "b"
		},
		// Replacement where s2 contains s1 (expands output)
		{
			"s2 contains s1",
			"abc", "abxxc",
			"b", "bxx"
		},
		// Replacement where s1 contains s2 (shrinks output)
		{
			"s1 contains s2",
			"abxxc", "abc",
			"xx", ""
		}
	};

	std::cout << YEL "=== Running test for replaceLine() ===\n" RESET;
	size_t	numTests = sizeof(test) / sizeof(test[0]);
	for (size_t i = 0; i < numTests; i++)
	{
		LineTestCase& t = test[i];
		std::cout << BLU "Test[" << i << "] " RESET << t.desc << '\n';
		std::string result = replaceLine(t.line, t.s1, t.s2);

		std::cout << "Result:   " << result << '\n'
				  << "Expected: " << t.expected << '\n'
				  << "Line:     " << t.line << '\n'
				  << "s1 input: " << t.s1 << '\n'
				  << "s2 input: " << t.s2 << '\n';

		if (result == t.expected)
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
	}
	std::cout << BLU "========= replaceLine summary ========" RESET << '\n'
			  << GRN "Tests passed: " << passed << RESET << '\n'
			  << RED "Tests failed: " << failed << RESET << '\n'
			  << "Total tests: " << numTests << '\n';	
	if (failed == 0)
		std::cout << GRN "All tests passed!\n" RESET;

	std::cout << BLU "=======================================\n" RESET;
	std::cout << YEL "=============END UNIT TEST=============\n" RESET;
	return (failed);
}
