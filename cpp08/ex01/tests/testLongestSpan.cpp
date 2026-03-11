/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testLongestSpan.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:09:55 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/11 09:09:58 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Span.hpp"
#include "Logger.hpp"
#include <climits>

int testLongestSpan()
{
	int failed = 0;
	int	total = 0;

	printHeader("Longest Span suite");
	// longest is UINT_MAX
	{
		Span a(3);
		a.addNumber(INT_MIN);
		a.addNumber(INT_MAX);
		a.addNumber(42);

		if (!assertEqual("longest fits in unsigned int", UINT_MAX, a.longestSpan()))
			failed++;
		total++;

	}
	// longest is 0
	{
		Span a(2);
		a.addNumber(42);
		a.addNumber(42);

		if (!assertEqual("longest is 0", 0, a.longestSpan()))
			failed++;
		total++;

	}
	// longest is 84
	{
		Span a(4);
		a.addNumber(-42);
		a.addNumber(42);
		a.addNumber(32);
		a.addNumber(22);

		if (!assertEqual("longest is 84", 84, a.longestSpan()))
			failed++;
		total++;

	}
	// not enough numbers should throw
	{
		Span a(1);
		a.addNumber(-42);
		bool thrown = false;
		try
		{
			a.longestSpan();
		}
		catch (Span::NoSpanException& e)
		{
			thrown = true;
		}
		if (!assertEqual("No span - should throw", true, thrown))
			failed++;
		total++;
	}
	printSummary(failed, total);
	return (failed);
}
