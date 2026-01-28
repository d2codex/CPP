/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testToInt.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:56:38 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/28 16:56:39 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "colors.hpp"
#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <climits> 

int testToInt(void)
{
	printHeader("toInt");
	
	int			failed = 0;
	int			total = 0;
	const int	fractionalBits = 8;
	const int	scale = 1 << fractionalBits;

	/* ============================= */
	/*   INT CONSTRUCTOR TESTS       */
	/* ============================= */

	// Case 1: normal int
	{
		Fixed a(10);
		total++;
		if (!assertEqualInt("int: normal", 10, a.toInt()))
			{ failed++; }
	}

	// Case 2: negative int
	{
		Fixed a(-10);
		total++;
		if (!assertEqualInt("int: negative", -10, a.toInt()))
			{ failed++; }
	}

	// Case 3: zero
	{
		Fixed a(0);
		total++;
		if (!assertEqualInt("int: zero", 0, a.toInt()))
			{ failed++; }
	}

	/* ============================= */
	/*   FLOAT CONSTRUCTOR TESTS     */
	/* ============================= */

	// Case 4: normal float
	{
		const float input = 42.42f;
		Fixed b(input);
		const int expected = static_cast<int>(roundf(input * scale)) >> fractionalBits;
		total++;
		if (!assertEqualInt("float: normal", expected, b.toInt()))
			{ failed++; }
	}

	// Case 5: negative float
	{
		const float input = -42.42f;
		Fixed b(input);
		const int expected = static_cast<int>(roundf(input * scale)) >> fractionalBits;
		total++;
		if (!assertEqualInt("float: negative", expected, b.toInt()))
			{ failed++; }
	}

	// Case 6: exact float (no fraction)
	{
		const float input = 42.0f;
		Fixed b(input);
		const int expected = static_cast<int>(roundf(input * scale)) >> fractionalBits;
		total++;
		if (!assertEqualInt("float: exact", expected, b.toInt()))
			{ failed++; }
	}

	// Case 7: small positive fraction (<1)
	{
		const float input = 0.99f;
		Fixed b(input);
		const int expected = static_cast<int>(roundf(input * scale)) >> fractionalBits;
		total++;
		if (!assertEqualInt("float: small positive", expected, b.toInt()))
			{ failed++; }
	}

	// Case 8: small negative fraction (> -1)
	{
		const float input = -0.99f;
		Fixed b(input);
		const int expected = static_cast<int>(roundf(input * scale)) >> fractionalBits;
		total++;
		if (!assertEqualInt("float: small negative", expected, b.toInt()))
			{ failed++; }
	}

	// Case 9: large float (safe)
	{
		const float input = 123456.78f;
		Fixed b(input);
		const int expected = static_cast<int>(roundf(input * scale)) >> fractionalBits;
		total++;
		if (!assertEqualInt("float: large", expected, b.toInt()))
			{ failed++; }
	}

	printSummary(failed, total);
	return(failed);
}
