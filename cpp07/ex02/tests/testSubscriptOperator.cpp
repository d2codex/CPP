/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testSubscriptOperator.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:17:52 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/04 10:17:53 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Array.hpp"
#include "Logger.hpp"

int testSubscriptOperator()
{
	int failed = 0;
	int	total = 0;

	printHeader("Subscript Operator suite");
	// non const assignment and out of bounds check
	{
		Array<int> a(3);
		a[0] = 42;
		a[1] = 24;
		a[2] = -42;

		if (!assertEqual("size matches", 3, a.size()))
			failed++;
		total++;

		if (!assertEqual("index 0 matches", 42, a[0]))
			failed++;
		total++;

		if (!assertEqual("index 1 matches", 24, a[1]))
			failed++;
		total++;

		if (!assertEqual("index 2 matches", -42, a[2]))
			failed++;
		total++;


		bool thrown = false;
		try
		{
			a[3]; // should throw
		}
		catch (const std::out_of_range& e)
		{
			//LOG_ERROR() << e.what();
			thrown = true;
		}
		if (!assertEqual("nconst out of bounds - a[3] should throw", true, thrown))
			failed++;
		total++;
	}
	// const array
	{
		const Array<char> a(3);
	
		bool thrown = false;
		try
		{
			a[3]; // should throw
		}
		catch (const std::out_of_range& e)
		{
			//LOG_ERROR() << e.what();
			thrown = true;
		}
		if (!assertEqual("const out of bounds - a[3] should throw", true, thrown))
			failed++;
		total++;
	}
	printSummary(failed, total);
	return (failed);
}
