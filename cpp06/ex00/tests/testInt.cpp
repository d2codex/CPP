/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testInt.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:04:21 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/24 16:04:22 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "ScalarConverter.hpp"

int	testInt()
{
	int	failed = 0;
	int	total = 0;

	printHeader("Int Suite");
	// test int 0
	{
		printHeader("int 0 - char non displayable");
		ScalarConverter::Scalar s = ScalarConverter::convert("0");

		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 0);
		assert(s.f == 0.0f);
		assert(s.d == 0.0);
		total++;
	}
	// highest displayable char 126
	{
		printHeader("highest displayable char 126");
		ScalarConverter::Scalar s = ScalarConverter::convert("126");

		assert(s.c == '~');
		assert(s.i == 126);
		assert(s.f == 126.0f);
		assert(s.d == 126.0);
		total++;
	}
	// non displayable 127
	{
		printHeader("non displayable 127");
		ScalarConverter::Scalar s = ScalarConverter::convert("127");

		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 127);
		assert(s.f == 127.0f);
		assert(s.d == 127.0);
		total++;
	}
	// char impossible 128
	{
		printHeader("char impossible 128");
		ScalarConverter::Scalar s = ScalarConverter::convert("128");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.i == 128);
		assert(s.f == 128.0f);
		assert(s.d == 128.0);
		total++;
	}
	// lowest displayable char 32
	{
		printHeader("lowest displayable char 32");
		ScalarConverter::Scalar s = ScalarConverter::convert("32");

		assert(s.c == ' ');
		assert(s.i == 32);
		assert(s.f == 32.0f);
		assert(s.d == 32.0);
		total++;
	}
	// non displayable 31
	{
		printHeader("non displayable 31");
		ScalarConverter::Scalar s = ScalarConverter::convert("31");

		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 31);
		assert(s.f == 31.0f);
		assert(s.d == 31.0);
		total++;
	}
	// char impossible negative -1
	{
		printHeader("char impossible (neg) -1");
		ScalarConverter::Scalar s = ScalarConverter::convert("-1");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.i == -1);
		assert(s.f == -1.0f);
		assert(s.d == -1.0);
		total++;
	}
	// int max
	{
		printHeader("int max 2147483647");
		ScalarConverter::Scalar s = ScalarConverter::convert("2147483647");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.i == 2147483647);
		assert(s.f == 2147483647.0f);
		assert(s.d == 2147483647.0);
		total++;
	}
	// int min
	{
		printHeader("int min -2147483648");
		ScalarConverter::Scalar s = ScalarConverter::convert("-2147483648");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.i == -2147483648);
		assert(s.f == -2147483648.0f);
		assert(s.d == -2147483648.0);
		total++;
	}
	// out of range 2147483648
	{
		printHeader("out of range 2147483648 should throw");
		expect_throw("2147483648");
		total++;
	}
	// out of range -2147483649
	{
		printHeader("out of range -2147483649 should throw");
		expect_throw("-2147483649");
		total++;
	}

	printSummary(failed, total);
	return (failed);
}

