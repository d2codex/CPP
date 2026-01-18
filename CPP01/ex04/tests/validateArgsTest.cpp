#include "replace.hpp"
#include "tests.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>
#include <fstream>

struct TestCase
{
	std::string desc;
	std::string	filename;
	std::string expected;
	std::string	s1;
	std::string s2;
	bool		shouldPass;
};

int	validateArgsTest()
{
	int passed = 0;
	int failed = 0;

	TestCase test[] = {
		{
			"Valid normal case",
			"testFiles/loremIpsum.txt",
			"",
			"a", "b", true
		},
		{
			"Invalid permission denied",
			"testFiles/permissionDenied.txt",
			"Error: cannot open file",
			"a", "b", false
		},
		{
			"Invalid s1 is empty",
			"testFiles/loremIpsum.txt",
			"Error: Search string cannot be empty",
			"", "b", false
		},
		{
			"Valid s1 is tab",
			"testFiles/loremIpsum.txt",
			"",
			"\t", "b", true
		},
		{
			"Valid empty file",
			"testFiles/emptyFile.txt",
			"",
			"a", "b", true
		},
		{
			"Valid s1 is space",
			"testFiles/loremIpsum.txt",
			"",
			" ", "b", true
		},
		{
			"Valid s2 is empty",
			"testFiles/loremIpsum.txt",
			"",
			"a", "", true
		},

	};

	std::cout << YEL "=== Running test for validateArgs() ===\n" RESET;
	size_t	numTests = sizeof(test) / sizeof(test[0]);

	for (size_t i = 0; i < numTests; i++)
	{
		std::cout << BLU "Test[" << i << "] " RESET << test[i].desc << '\n';
		int result = validateArgs(test[i].filename, test[i].s1, test[i].s2);

		if (!test[i].expected.empty())
			std::cout << "Expected: " << test[i].expected << '\n';
		std::cout << "Filename: " << test[i].filename << '\n'
				  << "s1 input: " << test[i].s1 << '\n'
				  << "s2 input: " << test[i].s2 << '\n';

		if (result == test[i].shouldPass)
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

	std::cout << BLU "========= validateArgs summary ========" RESET << '\n'
			  << GRN "Tests passed: " << passed << RESET << '\n'
			  << RED "Tests failed: " << failed << RESET << '\n'
			  << "Total tests: " << numTests << '\n';	
	if (failed == 0)
		std::cout << GRN "All tests passed!\n" RESET;

	std::cout << BLU "=======================================\n" RESET;
	std::cout << YEL "=============END UNIT TEST=============\n" RESET;
	return (failed);
}
