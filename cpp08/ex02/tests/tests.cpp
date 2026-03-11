/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:13:04 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/11 09:13:05 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
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
