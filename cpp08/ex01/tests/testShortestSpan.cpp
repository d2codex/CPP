/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testShortestSpan.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:10:06 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/11 09:10:08 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Span.hpp"
#include "Logger.hpp"
#include <climits>

int testShortestSpan()
{
	int failed = 0;
	int	total = 0;

	printHeader("Shortest Span suite");
	// shortest is UINT_MAX
	{
		Span a(2);
		a.addNumber(INT_MIN);
		a.addNumber(INT_MAX);

		if (!assertEqual("shortest fits in unsigned int", UINT_MAX, a.shortestSpan()))
			failed++;
		total++;

	}
	// shortest is 0
	{
		Span a(2);
		a.addNumber(42);
		a.addNumber(42);

		if (!assertEqual("shortest is 0", 0, a.shortestSpan()))
			failed++;
		total++;

	}
	// shortest is 10
	{
		Span a(4);
		a.addNumber(-42);
		a.addNumber(42);
		a.addNumber(32);
		a.addNumber(22);

		if (!assertEqual("shortest is 10", 10, a.shortestSpan()))
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
			a.shortestSpan();
		}
		catch (Span::NoSpanException& e)
		{
			thrown = true;
		}
		if (!assertEqual("no span - should throw", true, thrown))
			failed++;
		total++;
	}
	printSummary(failed, total);
	return (failed);
}
