/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testDivision.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:26:35 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/29 22:26:36 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Fixed.hpp"
#include "colors.hpp"

int	testDivision(void)
{
	printHeader("Division");
	int		failed = 0;
	int		total = 0;
	Fixed	a;
	
	// int / int
	{
		a = Fixed(10) / Fixed(2);
		total++;
		if (!assertEqualFloat("int / int (+,+)", 5.0f, a.toFloat()))
			failed++;
	}
	// int / float
	{
		a = Fixed(10) / Fixed(2.5f);
		total++;
	if (!assertEqualFloat("int / float (+,+)", 4.0f, a.toFloat()))
			failed++;
	}
	// float / int
	{
		a = Fixed(7.5f) / Fixed(3);
		total++;
		if (!assertEqualFloat("float / int (+,+)", 2.5f, a.toFloat()))
			failed++;
	}
	// float / float
	{
		a = Fixed(5.5f) / Fixed(2.0f);
		total++;
		if (!assertEqualFloat("float / float (+,+)", 2.75f, a.toFloat()))
			failed++;
	}
	// + / -
	{
		a = Fixed(10) / Fixed(-2);
		total++;
		if (!assertEqualFloat("int / int (+,-)", -5.0f, a.toFloat()))
			failed++;
	}
	// - / +
	{
		a = Fixed(-10) / Fixed(2);
		total++;
		if (!assertEqualFloat("int / int (-,+)", -5.0f, a.toFloat()))
			failed++;
	}
	// - / -
	{
		a = Fixed(-12) / Fixed(-4);
		total++;
		if (!assertEqualFloat("int / int (-,-)", 3.0f, a.toFloat()))
			failed++;
	}
	// small numbers
	{
		a = Fixed(0.5f) / Fixed(0.25f);
		total++;
		if (!assertEqualFloat("small / small", 2.0f, a.toFloat()))
			failed++;
	}
	// divide by 1
	{
		a = Fixed(5.5f) / Fixed(1);
		total++;
		if (!assertEqualFloat("float / 1", 5.5f, a.toFloat()))
			failed++;
	}
	// divide 0 by number
	{
		a = Fixed(0) / Fixed(5);
		total++;
		if (!assertEqualFloat("0 / int", 0.0f, a.toFloat()))
			failed++;
	}
	// divide by -1
	{
		a = Fixed(10) / Fixed(-1);
		total++;
		if (!assertEqualFloat("int / -1", -10.0f, a.toFloat()))
			failed++;
	}
	// fractional result
	{
		a = Fixed(7) / Fixed(2);
		total++;
		if (!assertEqualFloat("7 / 2 = 3.5", 3.5f, a.toFloat()))
			failed++;
	}
	// divide by larger number (result < 1)
	{
		a = Fixed(3) / Fixed(4);
		total++;
		if (!assertEqualFloat("3 / 4 = 0.75", 0.75f, a.toFloat()))
			failed++;
	}
	// precision test
	{
		a = Fixed(1) / Fixed(3);
		total++;
		if (!assertEqualFloat("1 / 3 (precision)", 0.33203125f, a.toFloat()))
			failed++;
	}
	//expect fail tests
	{
		total++;
		try
		{
			a = Fixed(10) / Fixed(0);
			std::cout << red("FAIL: divide by zero - no exception thrown");
			failed++;
		}
		catch (const std::domain_error& e)
		{
			std::cout << grn("PASS: ")
					  << "divide by zero - exception caught" << '\n';
		}
		catch (...)
		{
			std::cout << red("FAIL: divide by zero - wrong exception type");
			failed++;
		}
	}
	// divide by zero (float)
	{
		total++;
		try
		{
			a = Fixed(5.5f) / Fixed(0.0f);
			std::cout << red("FAIL: divide by zero (float) - no exception thrown");
			failed++;
		}
		catch (const std::domain_error& e)
		{
			std::cout << grn("PASS: ")
					  << "divide by zero (float) - exception caught" << '\n';
		}
		catch (...)
		{
			std::cout << red("FAIL: divide by zero (float) - wrong exception type");
			failed++;
		}
	}
	printSummary(failed, total);
	return (failed);
}
