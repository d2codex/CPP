/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testToFloat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:56:31 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/28 16:56:33 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "colors.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <climits>

int	testToFloat(void)
{
	printHeader("To Float");
	
	int			failed = 0;
	int			total = 0;
	int			fractionalBits = 8;
	const int	scale = 1 << fractionalBits;
	const int	safetyMargin = 1;
	const int	approxMax = (INT_MAX / scale) - safetyMargin;
	const int	approxMin = (INT_MIN / scale) + safetyMargin;

	/* ============================= */
	/*   INT CONSTRUCTOR TESTS       */
	/* ============================= */

	// Case 1: normal integer
	{
		Fixed a(10);
		total++;
		if (!assertEqualFloat("int: normal", 10.0f, a.toFloat()))
			{ failed++; }
	}

	// Case 2: negative integer
	{
		Fixed a(-10);
		total++;
		if (!assertEqualFloat("int: negative", -10.0f, a.toFloat()))
			{ failed++; }
	}

	// Case 3: zero
	{
		Fixed a(0);
		total++;
		if (!assertEqualFloat("int: zero", 0.0f, a.toFloat()))
			{ failed++; }
	}

	// Case 4: negative zero
	{
		Fixed a(-0);
		total++;
		if (!assertEqualFloat("int: negative zero", 0.0f, a.toFloat()))
			{ failed++; }
	}

	/* ============================= */
	/*   FLOAT CONSTRUCTOR TESTS     */
	/* ============================= */

	// Case 5: positive float
	{
		Fixed b(42.42f);
		total++;
		if (!assertEqualFloat("float: positive", 42.42f, b.toFloat()))
			{ failed++; }
	}

	// Case 6: negative float
	{
		Fixed b(-10.5f);
		total++;
		if (!assertEqualFloat("float: negative", -10.5f, b.toFloat()))
			{ failed++; }
	}

	// Case 7: smallest exact fraction (1 / 256)
	{
		Fixed b(1.0f / 256);
		total++;
		if (!assertEqualFloat("float: small fraction", 1.0f / 256, b.toFloat()))
			{ failed++; }
	}

	// Case 8: approximate max
	{
		Fixed b(static_cast<float>(approxMax));
		total++;
		if (!assertEqualFloat("float: approx max", static_cast<float>(approxMax), b.toFloat()))
			{ failed++; }
	}

	// Case 9: approximate min
	{
		Fixed b(static_cast<float>(approxMin));
		total++;
		if (!assertEqualFloat("float: approx min", static_cast<float>(approxMin), b.toFloat()))
			{ failed++; }
	}
	printSummary(failed, total);
	return (failed);
}
