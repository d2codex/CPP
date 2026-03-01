/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMax.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:39:19 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/01 19:39:21 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "whatever.hpp"
#include <climits>
#include <cfloat>
#include <limits>

const float  FLT_TOLERANCE  = 1e-5;
const double DBL_TOLERANCE = 1e-12;

int	testMax()
{
	int	failed = 0;
	int	total = 0;

	printHeader("Max suite");
	// int postive
	{
		int a = 2;
		int b = 3;
		int result = ::max(a, b);
		if (!assertEqual("int (2, 3)", 3, result))
			failed++;
		total++;
	}
	// int negative
	{
		int a = -2;
		int b = -3;
		int result = ::max(a, b);
		if (!assertEqual("int (-2, -3)", -2, result))
			failed++;
		total++;
	}
	// int zero / positive
	{
		int a = 0;
		int b = 2;
		int result = ::max(a, b);
		if (!assertEqual("int (0, 2)", 2, result))
			failed++;
		total++;
	}
	// int zero / negative
	{
		int a = -2;
		int b = 0;
		int result = ::max(a, b);
		if (!assertEqual("int (-2, 0)", 0, result))
			failed++;
		total++;
	}
	// int INT_MAX / INT_MIN
	{
		int a = INT_MIN;
		int b = INT_MAX;
		int result = ::max(a, b);
		if (!assertEqual("int (INT_MIN, INT_MAX)", INT_MAX, result))
			failed++;
		total++;
	}
	// int equal
	{
		int a = 5;
		int b = 5;
		const int& result = ::max(a, b);
		if (!assertEqual("int (5, 5) returns second", &b, &result))
			failed++;
		total++;
	}
	// float positive
	{
		float a = 1.5f;
		float b = 2.3f;
		float result = ::max(a, b);
		if (!almostEqual("float (1.5f, 2.3f)", 2.3f, result, FLT_TOLERANCE))
			failed++;
		total++;
	}
	// float negative / zero
	{
		float a = -2.5f;
		float b = 0.0f;
		float result = ::max(a, b);
		if (!almostEqual("float (-2.5f, 0.0f)", 0.0f, result, FLT_TOLERANCE))
			failed++;
		total++;
	}
	// float zero / zero
	{
		float a = 0.0f;
		float b = 0.0f;
		const float& result = ::max(a, b);
		if (!assertEqual("float (0.0f, 0.0f)", &b, &result))
			failed++;
		total++;
	}
	// float FLT_MAX / -FLT_MAX
	{
		float a = -FLT_MAX;
		float b = FLT_MAX;
		float result = ::max(a, b);
		if (!almostEqual("float (-FLT_MAX, FLT_MAX)", FLT_MAX, result, FLT_TOLERANCE))
			failed++;
		total++;
	}
	// float FLT_MIN / -FLT_MIN
	{
		float a = -FLT_MIN;
		float b = FLT_MIN;
		float result = ::max(a, b);
		if (!almostEqual("float (-FLT_MIN, FLT_MIN)", FLT_MIN, result, FLT_TOLERANCE))
			failed++;
		total++;
	}
	// float NAN
	{
		float a = NAN;
		float b = 5.0f;
		float result = ::max(a, b);
		if (!assertEqual("float (NAN, 5.0f)", 5.0f, result))
			failed++;
		total++;
	}
	// float INFINITY
	{
		float a = -INFINITY;
		float b = INFINITY;
		float result = ::max(a, b);
		if (!assertEqual("float (-INFINITY, INFINITY)", INFINITY, result))
			failed++;
	}
	// double positive
	{
		double a = 1.51234567;
		double b = 2.31234567;
		double result = ::max(a, b);
		if(!almostEqual("double (1.5, 2.3)", 2.31234567, result, DBL_TOLERANCE))
		total++;
	}
	// double negative / zero
	{
		double a = -2.51234567;
		double b = 0.01234567;
		double result = ::max(a, b);
		if (!almostEqual("double (-2.5, 0.0)", 0.01234567, result, DBL_TOLERANCE))
			failed++;
		total++;
	}
	// double DBL_MAX / -DBL_MAX
	{
		double a = -DBL_MAX;
		double b = DBL_MAX;
		double result = ::max(a, b);
		if (!almostEqual("double (-DBL_MAX, DBL_MAX)", DBL_MAX, result, DBL_TOLERANCE))
			failed++;
		total++;
	}
	// double DBL_MIN / -DBL_MIN
	{
		double a = -DBL_MIN;
		double b = DBL_MIN;
		double result = ::max(a, b);
		if (!almostEqual("double (-DBL_MIN, DBL_MIN)", DBL_MIN, result, DBL_TOLERANCE))
			failed++;
		total++;
	}
	// double INFINITY
	{
		double a = -std::numeric_limits<double>::infinity();
		double b = std::numeric_limits<double>::infinity();
		double result = ::max(a, b);
		if (!assertEqual("double (-INFINITY, INFINITY)",
				std::numeric_limits<double>::infinity(), static_cast<double>(result)))
			failed++;
		total++;
	}
	// double NAN
	{
		double a = NAN;
		double b = 5.0123456789;
		double result = ::max(a, b);
		if (!assertEqual("double (NAN, 5.0123456789)", 5.0123456789, result))
			failed++;
		total++;
	}
	// char
	{
		char a = 'a';
		char b = 'z';
		char result = ::max(a, b);
		if (!assertEqual("char (a, z)", 'z', result))
			failed++;
		total++;
	}
	// std::string
	{
		std::string a = "abc";
		std::string b = "def";
		std::string result = ::max(a, b);
		if (!assertEqual("std::string (abc, def)", "def", result))
			failed++;
		total++;
	}
	// std::string equal
	{
		std::string a = "ABC";
		std::string b = "ABC";
		const std::string& result = ::max(a, b);
		if (!assertEqual("std::string (ABC, ABC) returns second", &b, &result))
			failed++;
		total++;
	}
	// bool
	{
		bool a = true;
		bool b = false;
		bool result = ::max(a, b);
		assert(b < a);
		if (!assertEqual("bool (true, false)", true, result))
			failed++;
		total++;
	}

	printSummary(failed, total);
	return (failed);
}
