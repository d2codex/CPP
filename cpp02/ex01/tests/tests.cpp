#include "tests.hpp"
#include "colors.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

void printHeader(const std::string& testName)
{
    std::cout << YEL << "Testing " << testName
			  << RESET << '\n';
}

void printSummary(const std::string& testName, int failed, int total)
{
    std::cout << blu("=============== Summary ===============\n")
			  << "Test: " << testName << '\n'
              << red("Tests failed: ") << failed << '\n'
              << "Total tests: " << total << '\n';

    if (failed == 0)
        std::cout << grn("All tests passed!\n")
				  << blu("=============END UNIT TEST=============\n");
}

bool assertEqualInt(const std::string& name, int expected, int actual)
{
	if (expected == actual)
	{
		std::cout << grn("PASS ") << name << '\n';
		return (true);
	}
	std::cout << red("FAIL ") << name << '\n'
			  << "expected: " << expected << '\n'
			  << "actual  : " << actual << '\n';
	return (false);
}
