#include "replace.hpp"
#include "tests.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>
#include <fstream>

struct TestCase
{
	std::string desc;
	std::string line;
	std::string expected;
	std::string	s1;
	std::string s2;
	bool		shouldPass;
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

	TestCase test[] = {
		// Normal
		{
			"Valid normal case",
			"hallo", "hbllo",
			"a", "b", true
		},
		// No match (should still pass, just no change)
		{
			"No match case",
			"hello", "hello",
			"x", "y", true
		},
		// Replace with longer string
		{
			"Replace with longer string",
			"hello", "heyyyo",
			"ll", "yyy", true
		},
		// Replace with shorter string
		{
			"Replace with shorter string",
			"hello", "heo",
			"ll", "", true
		},
		// Replace with empty line (still valid if s1 is not empty)
		{
			"Valid empty line",
			"", "",
			"a", "b", true
		},
		// Replace with whitespace (space)
		{
			"Replace space",
			"a b c", "a-X-b-X-c",
			" ", "-X-", true
		},
		// Replace with tab
		{
			"Replace tab",
			"a\tb\tc", "a-X-b-X-c",
			"\t", "-X-", true
		},
		// Replace with special characters
		{
			"Replace special chars",
			"hello!world!", "hello?world?",
			"!", "?", true
		},
		// Multiple occurrences
		{
			"Multiple occurrences",
			"aaaa", "bbbb",
			"a", "b", true
		},
		// Overlapping pattern case (important!)
		// Example: replace "aa" in "aaaa" -> should become "bb" if handled correctly
		{
			"Overlapping pattern",
			"aaaa", "bb",
			"aa", "b", true
		},
		// Replacement where s2 contains s1 (expands output)
		{
			"s2 contains s1",
			"abc", "abxxc",
			"b", "bxx", true
		},
		// Replacement where s1 contains s2 (shrinks output)
		{
			"s1 contains s2",
			"abxxc", "abc",
			"xx", "", true
		}
	};

	std::cout << YEL "=== Running test for replaceLine() ===\n" RESET;
	size_t	numTests = sizeof(test) / sizeof(test[0]);

	for (size_t i = 0; i < numTests; i++)
	{
		std::cout << BLU "Test[" << i << "] " RESET << test[i].desc << '\n';
		std::string result = replaceLine(test[i].line, test[i].s1, test[i].s2);

		std::cout << "Result:   " << result << '\n'
				  << "Expected: " << test[i].expected << '\n'
				  << "Line:     " << test[i].line << '\n'
				  << "s1 input: " << test[i].s1 << '\n'
				  << "s2 input: " << test[i].s2 << '\n';

		if (result == test[i].expected)
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
