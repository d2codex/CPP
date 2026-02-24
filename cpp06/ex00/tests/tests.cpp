/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:04:26 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/24 16:04:28 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "tests.hpp"
#include "Logger.hpp"
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

void expect_throw(const std::string& input)
{
    bool thrown = false;

    try
    {
        ScalarConverter::convert(input);
    }
    catch (const std::exception& e)
    {
        thrown = true;
		std::cout << e.what() << '\n';
    }

    assert(thrown);
}
