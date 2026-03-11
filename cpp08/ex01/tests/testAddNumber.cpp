/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testAddNumber.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:09:42 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/11 09:09:44 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Span.hpp"
#include "Logger.hpp"

int testAddNumber()
{
	int failed = 0;
	int	total = 0;

	printHeader("Add Number suite");
	// add number
	{
		Span a(4);
		a.addNumber(INT_MIN);
		a.addNumber(INT_MAX);
		a.addNumber(42);
		a.addNumber(0);

		if (!assertEqual("verify with longestSpan", UINT_MAX, a.longestSpan()))
			failed++;
		total++;

		if (!assertEqual("verify with shortestSpan", 42, a.shortestSpan()))
			failed++;
		total++;
	}
	// add number after max capacity (2000000)
	{
		srand(time(NULL));
		std::vector<int> v = generateRandomNumbers< std::vector<int> >(2000000);
		Span a(2000000);
		a.addNumber(v.begin(), v.end());

		bool thrown = false;
		try
		{
			a.addNumber(25);
		}
		catch (Span::SpanFullException& e)
		{
			thrown = true;
		}

		if (!assertEqual("test max capicity, add should throw", true, thrown))
			failed++;
		total++;
	}
	// vector full add should throw
	{
		Span a(2);
		a.addNumber(-42);
		a.addNumber(42);
		bool thrown = false;
		try
		{
			a.addNumber(0);
		}
		catch (Span::SpanFullException& e)
		{
			thrown = true;
		}
		if (!assertEqual("span full - should throw", true, thrown))
			failed++;
		total++;
	}
	printSummary(failed, total);
	return (failed);
}

