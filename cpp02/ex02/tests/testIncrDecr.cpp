/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testIncrDecr.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:26:46 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/29 22:26:48 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "colors.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

int	testIncrDecr(void)
{
	printHeader("Increment / Decrement");

	int	failed = 0;
	int total = 0;
	int	fractionalBits = 8;
	int	scale = 1 << fractionalBits;

	//====pre increment===//
	// normal int
	{
		Fixed a(5);
		++a;
		float expected = (5 * scale + 1) / (float)scale;
		total++;
		if (!assertEqualFloatExact("normal int", expected, a.toFloat()))
		{failed++;}
	}
	// negative int
	{
		Fixed a(-5);
		++a;
		float expected = (-5 * scale + 1) / (float)scale;
		total++;
		if (!assertEqualFloatExact("normal int", expected, a.toFloat()))
		{failed++;}
	}
	// normal float
	{
		Fixed a(5.2f);
		total++;
		++a;
		float expected = (roundf(5.2f * scale) + 1) / (float)scale;
		if (!assertEqualFloatExact("normal float", expected, a.toFloat()))
		{failed++;}
	}
	// negative float
	{
		Fixed a(-5.2f);
		total++;
		++a;
		float expected = (roundf(-5.2f * scale) + 1) / (float)scale;
		if (!assertEqualFloatExact("normal float", expected, a.toFloat()))
		{failed++;}
	}

	//====post increment===//
	// normal int
	{
		Fixed a(6);
		Fixed result = a++; // return value is stored here. 
							// but the object value has changed
		total++;
		if (!assertEqualFloat("normal int++", 6, result.toFloat()))
		{failed++;}
	}
	// negative int
	{
		Fixed a(-7);
		Fixed result = a++;
		total++;
		if (!assertEqualFloat("normal int", -7, result.toFloat()))
		{failed++;}
	}
	// normal float
	{
		Fixed a(5.78f);
		Fixed result = a++;
		total++;
		if (!assertEqualFloat("normal float", 5.78f, result.toFloat()))
		{failed++;}
	}
	// negative float
	{
		Fixed a(-5.88f);
		Fixed result = a++;
		total++;
		if (!assertEqualFloat("normal float", -5.88f, result.toFloat()))
		{failed++;}
	}


	printSummary(failed, total);
	return (failed);
}
