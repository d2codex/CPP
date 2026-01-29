/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testAddition.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:26:13 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/29 22:39:53 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Fixed.hpp"
#include "colors.hpp"

int	testAddition(void)
{
	printHeader("Addition");
	int		failed = 0;
	int		total = 0;
	Fixed	a;

	// int + int
	{
		a = Fixed(5) + Fixed(2);
		total++;
		if (!assertEqualFloat("int + int (+,+)", 7.0f, a.toFloat()))
			failed++;
	}
	// int + float
	{
		a = Fixed(5) + Fixed(2.5f);
		total++;
		if (!assertEqualFloat("int + float (+,+)", 7.5f, a.toFloat()))
			failed++;
	}
	// float + int
	{
		a = Fixed(2.5f) + Fixed(4);
		total++;
		if (!assertEqualFloat("float + int (+,+)", 6.5f, a.toFloat()))
			failed++;
	}
	// float + float
	{
		a = Fixed(1.5f) + Fixed(2.5f);
		total++;
		if (!assertEqualFloat("float + float (+,+)", 4.0f, a.toFloat()))
			failed++;
	}
	// + + -
	{
		a = Fixed(5) + Fixed(-2);
		total++;
		if (!assertEqualFloat("int + int (+,-)", 3.0f, a.toFloat()))
			failed++;
	}
	// - + -
	{
		a = Fixed(-3) + Fixed(-4);
		total++;
		if (!assertEqualFloat("int + int (-,-)", -7.0f, a.toFloat()))
			failed++;
	}
	// small numbers
	{
		a = Fixed(0.25f) + Fixed(0.5f);
		total++;
		if (!assertEqualFloat("small + small", 0.75f, a.toFloat()))
			failed++;
	}
	// zero addition
	{
		a = Fixed(5) + Fixed(0);
		total++;
		if (!assertEqualFloat("int + zero", 5.0f, a.toFloat()))
			failed++;
	}
	// negative + positive (crossing zero)
	{
		a = Fixed(-3.5f) + Fixed(3.5f);
		total++;
		if (!assertEqualFloat("negative + positive = zero", 0.0f, a.toFloat()))
			failed++;
	}

	// addition overflow (positive)
	{
		total++;
	try
	{
		a = Fixed(8388606) + Fixed(8388606);
		std::cout << red("FAIL addition overflow - no exception thrown\n");
		failed++;
	}
	catch (const std::overflow_error& e)
	{
		std::cout << grn("PASS ")
				  << "addition overflow - exception caught" << '\n';
	}
	catch (...)
	{
		std::cout << red("FAIL addition overflow - wrong exception type'\n");
		failed++;
	}
}
// addition underflow (negative)
{
	total++;
	try
	{
		a = Fixed(-8388607) + Fixed(-8388607);
		std::cout << red("FAIL addition underflow - no exception thrown");
		failed++;
	}
	catch (const std::overflow_error& e)
	{
		std::cout << grn("PASS ")
				  << "addition underflow - exception caught" << '\n';
	}
	catch (...)
	{
		std::cout << red("FAIL addition underflow - wrong exception type'\n");
		failed++;
	}
}
// addition at max boundary
{
	total++;
	try
	{
		a = Fixed(8388606) + Fixed(2);
		std::cout << red("FAIL addition max boundary - no exception thrown\n");
		failed++;
	}
	catch (const std::overflow_error& e)
	{
		std::cout << grn("PASS ")
				  << "addition max boundary - exception caught" << '\n';
	}
	catch (...)
	{
		std::cout << red("FAIL addition max boundary - wrong exception type\n");
		failed++;
	}
}
// addition at min boundary
{
	total++;
	try
	{
		a = Fixed(-8388607) + Fixed(-2);
		std::cout << red("FAIL addition min boundary - no exception thrown\n");
		failed++;
	}
	catch (const std::overflow_error& e)
	{
		std::cout << grn("PASS ")
				  << "addition min boundary - exception caught" << '\n';
	}
	catch (...)
	{
		std::cout << red("FAIL addition min boundary - wrong exception type\n");
		failed++;
	}
}
	printSummary(failed, total);
	return (failed);
}
