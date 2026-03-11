/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testAssignment.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:09:46 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/11 09:09:48 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Span.hpp"
#include "Logger.hpp"

int testAssignment()
{
	int failed = 0;
	int	total = 0;

	printHeader("Assignment Overload suite");
	// assignemnt
	{
		Span a(2);
		a.addNumber(1);
		a.addNumber(2);
		Span b(3);
		b = a;

		bool thrown = false;
		try
		{
			b.addNumber(-1);
		}
		catch (Span::SpanFullException& e)
		{
			thrown = true;
		}
		if (!assertEqual("b maxSize = 2, add should throw", true, thrown))
			failed++;
		total++;

		if (!assertEqual("shortestSpan a and b are equal",
				a.shortestSpan(), b.shortestSpan()))
			failed++;
		total++;

		if (!assertEqual("longestSpan a and b are equal",
				a.longestSpan(), b.longestSpan()))
			failed++;
		total++;
	}
	printSummary(failed, total);
	return (failed);
}

