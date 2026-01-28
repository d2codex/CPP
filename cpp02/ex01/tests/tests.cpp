/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:56:44 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/28 16:56:46 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool assertEqualFloat(const std::string& name,
					  float expected, float actual)
{
	float epsilon = 1.0f / 256.0f;
	if (std::fabs(expected - actual) <= epsilon)
	{
		std::cout << grn("PASS ") << name << '\n';
		return (true);
	}
	std::cout << red("FAIL ") << name << '\n'
			  << "expected: " << expected << '\n'
			  << "actual  : " << actual << '\n';
	return (false);
}
