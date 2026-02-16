#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

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

bool fileExists(const std::string& testName, const std::string& filename)
{
    std::ifstream f(filename.c_str());
	if (f.good())
	{
		std::cout << grn("PASS ") << testName << '\n';
		return (true);
	}
	std::cout << red("FAIL ") << testName << '\n'
			  << "file not found" << '\n';
	return (false);
}

bool fileDoesNotExist(const std::string& testName, const std::string& filename)
{
    std::ifstream f(filename.c_str());
    if (!f.good())
    {
        std::cout << grn("PASS ") << testName << '\n';
        return true;
    }
    else
    {
        std::cout << red("FAIL ") << testName << '\n';
        return false;
    }
}
