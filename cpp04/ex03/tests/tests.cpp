#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

void printHeader(const std::string& testName)
{
    std::cout << YEL << "Testing " << testName
			  << RESET << '\n';
}

void printSummary(int failed, int total)
{
    std::cout << blu("Unit Test Summary\n")
              << red("Tests failed: ") << failed << '\n'
              << "Total tests: " << total << '\n';

    if (failed == 0)
	{
        std::cout << grn("All tests passed!\n");
	}
	std::cout << yel("=======================================\n");
}

bool	assertEqual(const std::string& name, const std::string& expected,
					const std::string& actual)
{
	if (expected == actual)
	{
		std::cout << grn("PASS ") << name << '\n';
		return (true);
	}
	std::cout << red("FAIL ") << name << '\n'
			  << "expected: " << expected << '\n'
			  << "actual:   " << actual << '\n';
	return (false);
}

bool	assertNotEqPtr(const std::string& name, const void* ptr1, const void* ptr2)
{
	if (ptr1 != ptr2)
	{
		std::cout << grn("PASS ") << name << '\n';
		return (true);
	}
	std::cout << red("FAIL ") << name << '\n'
			  << "expected: " << ptr1 << '\n'
			  << "actual:   " << ptr2 << '\n';
	return (false);

}
