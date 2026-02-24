/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:03:29 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/24 16:03:30 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include "colors.hpp"
#include <cassert>
#include <cmath>
#include <cassert>

void	printHeader(const std::string& testName);
void	printSummary(int failed, int total);

/* helper for C-strings */
inline bool equalHelper(const char* a, const char* b)
{
	return (std::strcmp(a, b) == 0);
}

/* mixed string types */
inline bool equalHelper(const char* a, const std::string& b)
{
	return b == a;
}

inline bool equalHelper(const std::string& a, const char* b)
{
	return a == b;
}

/* generic helper for all other types */
template<typename T>
bool equalHelper(const T& a, const T& b)
{
	return (a == b);
}

/* template assertEqual using equalHelper */
template<typename T1, typename T2>
bool	assertEqual(const char* testName, const T1& expected,
					const T2& actual)
{
	if (equalHelper(expected, actual))
	{
		std::cout << grn("PASS ") << testName << '\n';
		return (true);
	}
	std::cout << red("FAIL ") << testName << '\n'
			  << "expected: " << expected << '\n'
			  << "actual:   " << actual << '\n';
	return (false);
}

/* template assertNotEqual using equalHelper */
template<typename T1, typename T2>
bool	assertNotEqual(const char* testName, const T1& expected,
					const T2& actual)
{
	if (!equalHelper(expected, actual))
	{
		std::cout << grn("PASS ") << testName << '\n';
		return (true);
	}
	std::cout << red("FAIL ") << testName << '\n'
			  << mag("results must be different") << '\n'
			  << "expected: " << expected << '\n'
			  << "actual:   " << actual << '\n';
	return (false);
}

template<typename T>
bool almostEqual(T value, T expected, T tolerance)
{
    return std::fabs(value - expected) < tolerance;
}

bool fileExists(const std::string& testName, const std::string& filename);
bool fileDoesNotExist(const std::string& testName, const std::string& filename);

void expect_throw(const std::string& input);

int	testChar();
int testInt();
int testFloat();
int	testDouble();
