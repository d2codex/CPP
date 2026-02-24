/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testDouble.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:22:07 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/24 14:46:24 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "ScalarConverter.hpp"
#include <cmath>

int	testDouble()
{
	int	failed = 0;
	int	total = 0;

	printHeader("Double Suite");
	// test int 0
	{
		printHeader("double 0.0");
		ScalarConverter::Scalar s = ScalarConverter::convert("0.0");

		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 0);
		assert(s.f == 0.0f);
		assert(s.d == 0.0);
		total++;
	}
	// highest displayable char 126
	{
		printHeader("highest displayable char 126.0");
		ScalarConverter::Scalar s = ScalarConverter::convert("126.0");

		assert(s.c == '~');
		assert(s.i == 126);
		assert(s.f == 126.0f);
		assert(s.d == 126.0);
		total++;
	}
	// non displayable 127
	{
		printHeader("non displayable 127.0");
		ScalarConverter::Scalar s = ScalarConverter::convert("127.0");

		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 127);
		assert(s.f == 127.0f);
		assert(s.d == 127.0);
		total++;
	}
	// char impossible 128
	{
		printHeader("char impossible 128.0");
		ScalarConverter::Scalar s = ScalarConverter::convert("128.0");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.i == 128);
		assert(s.f == 128.0f);
		assert(s.d == 128.0);
		total++;
	}
	// lowest displayable char 32
	{
		printHeader("lowest displayable char 32.0");
		ScalarConverter::Scalar s = ScalarConverter::convert("32.0");

		assert(s.c == ' ');
		assert(s.i == 32);
		assert(s.f == 32.0f);
		assert(s.d == 32.0);
		total++;
	}
	// non displayable 31
	{
		printHeader("non displayable 31.0");
		ScalarConverter::Scalar s = ScalarConverter::convert("31.0");

		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 31);
		assert(s.f == 31.0f);
		assert(s.d == 31.0);
		total++;
	}
	// char impossible negative -1
	{
		printHeader("char impossible (neg) -1.0");
		ScalarConverter::Scalar s = ScalarConverter::convert("-1.0");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.i == -1);
		assert(s.f == -1.0f);
		assert(s.d == -1.0);
		total++;
	}
	// int max
	{
		printHeader("int max 2147483647.0");
		ScalarConverter::Scalar s = ScalarConverter::convert("2147483647.0");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.i == 2147483647);
		assert(s.f == 2147483647.0f);
		assert(s.d == 2147483647.0);
		total++;
	}
	// int min
	{
		printHeader("int min -2147483648.0");
		ScalarConverter::Scalar s = ScalarConverter::convert("-2147483648.0");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.i == -2147483648);
		assert(s.f == -2147483648.0f);
		assert(s.d == -2147483648.0);
		total++;
	}
	// int overflow
	{
		printHeader("int overflow 2147483648.0");
		ScalarConverter::Scalar s = ScalarConverter::convert("2147483648.0");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(s.f == 2147483648.0f);
		assert(s.d == 2147483648.0);
		total++;
	}
	// int underflow
	{
		printHeader("int underflow -2147483649");
		ScalarConverter::Scalar s = ScalarConverter::convert("-2147483649.0");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(s.f == -2147483649.0f);
		assert(s.d == -2147483649.0);
		total++;
	}

	// float max
	{
		printHeader("double max 3.40282e+38");
		ScalarConverter::Scalar s = ScalarConverter::convert("3.40282e+38");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(s.f == 3.40282e+38f);
		assert(s.d == 3.40282e+38);
		total++;
	}
	// float min
	{
		printHeader("double min -3.40282e+38");
		ScalarConverter::Scalar s = ScalarConverter::convert("-3.40282e+38");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(s.f == -3.40282e+38f);
		assert(s.d == -3.40282e+38);
		total++;
	}
	// float overflow
	{
		printHeader("double overflow 3.40283e+38");
		ScalarConverter::Scalar s = ScalarConverter::convert("3.40283e+38");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::FLOAT_IMPOSSIBLE);
		assert(almostEqual(s.d, 3.40283e+38, 1e-10));
		total++;
	}
	// float underflow
	{
		printHeader("double underflow -3.40283e+38");
		ScalarConverter::Scalar s = ScalarConverter::convert("-3.40283e+38");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::FLOAT_IMPOSSIBLE);
		assert(almostEqual(s.d, -3.40283e+38, 1e-10));
		total++;
	}
	// DBL_MAX (largest positive)
	{
		printHeader("DBL MAX 1.79769e+308");
		ScalarConverter::Scalar s = ScalarConverter::convert("1.79769e+308");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::FLOAT_IMPOSSIBLE);
		assert(s.d == 1.79769e+308);
		total++;
	}
	// DBL_MIN (smallest positive number)
	{
		printHeader("DBL MIN 2.2250738585072014e-308");
		ScalarConverter::Scalar s = ScalarConverter::convert("2.2250738585072014e-308");

		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 0);
		assert(s.f == 0.0f);
		assert(s.d == 2.2250738585072014e-308);
		total++;
	}
	// -DBL_MAX (largest negative)
	{
		printHeader("-DBL_MAX -1.79769e+308");
		ScalarConverter::Scalar s = ScalarConverter::convert("-1.79769e+308");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::FLOAT_IMPOSSIBLE);
		assert(s.d == -1.79769e+308);
		total++;
	}
	// -DBL_MIN (smallest negative number)
	{
		printHeader("-DBL_MIN -2.2250738585072014e-308");
		ScalarConverter::Scalar s = ScalarConverter::convert("-2.2250738585072014e-308");

		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 0);
		assert(s.f == 0.0f);
		assert(s.d == -2.2250738585072014e-308);
		total++;
	}
/*	// double overflow lowercase e
	{
		printHeader("double overflow expect throw 3.40283e+38f");
		expect_throw("3.40283e+38f");
		total++;
	}
	// double underflow capitla E
	{
		printHeader("double underflow expect throw -3.40283E+38f");
		expect_throw("-3.40283E+38f");
		total++;
	}
*/

	// double number leading dot
	{
		printHeader("double number leading dot .123456");
		ScalarConverter::Scalar s = ScalarConverter::convert(".123456");
		
		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 0);
		assert(almostEqual(s.f, 0.123456f, 1e-5f));
		assert(almostEqual(s.d, 0.123456, 1e-10));
		total++;
	}
	// double lots of number after dot
	{
		printHeader("double lots of numbers after dot .123456789");
		ScalarConverter::Scalar s = ScalarConverter::convert(".123456789");
		
		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 0);
		assert(almostEqual(s.f, 0.123456789f, 1e-5f));
		assert(almostEqual(s.d, 0.123456789, 1e-10));
		total++;
	}

	// double literals -inf
	{
		printHeader("double litteral -inf");
		ScalarConverter::Scalar s = ScalarConverter::convert("-inf");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(std::isinf(s.f) && s.f < 0);
		assert(std::isinf(s.d) && s.d < 0);
		total++;
	}
	// double literals +inf
	{
		printHeader("double litteral +inf");
		ScalarConverter::Scalar s = ScalarConverter::convert("+inf");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(std::isinf(s.f) && s.f > 0);
		assert(std::isinf(s.d) && s.d > 0);
		total++;
	}
	// double literals nanf
	{
		printHeader("double litteral nan");
		ScalarConverter::Scalar s = ScalarConverter::convert("nan");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(std::isnan(s.f));
		assert(std::isnan(s.d));
		total++;
	}

	printSummary(failed, total);
	return (failed);
}



