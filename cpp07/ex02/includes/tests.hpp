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

/* generic helper for int and unsigned int types */
template<typename T1, typename T2>
inline bool equalHelper(const int& a, const unsigned int& b)
{
    return (static_cast<unsigned int>(a) == b);
}

inline bool equalHelper(const unsigned int& a, const int& b)
{
    return (a == static_cast<unsigned int>(b));
}

/* generic helper for pointers */
template<typename T>
bool equalHelper(const T* a, T* b)
{
	return (a == b);
}

template<typename T>
bool equalHelper(T* a, const T* b)
{
	return (a == b);
}

template<typename T>
bool equalHelper(const T* a, const T* b)
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

inline bool almostEqual(const char* testName,
						float actual, float expected, float tolerance)
{
	if (std::fabs(actual - expected) < tolerance)
	{
		std::cout << grn("PASS ") << testName << '\n';
		return (true);
	}
	std::cout << red("FAIL ") << testName << '\n'
			  << "expected: " << expected << '\n'
			  << "actual:   " << actual << '\n';
	return (false);

}

inline bool almostEqual(const char* testName,
						double actual, double expected, double tolerance)
{
	if (std::fabs(actual - expected) < tolerance)
	{
		std::cout << grn("PASS ") << testName << '\n';
		return (true);
	}
	std::cout << red("FAIL ") << testName << '\n'
			  << "expected: " << expected << '\n'
			  << "actual:   " << actual << '\n';
	return (false);

}

int	testDefaultCtor();
int	testParamCtor();
int	testCopyCtor();
