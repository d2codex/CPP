/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testParamCtor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:17:48 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/04 10:17:49 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Array.hpp"
#include "Logger.hpp"

int testParamCtor()
{
	int failed = 0;
	int	total = 0;

	printHeader("Parameterized Constructor suite");
	// non const int parameterized ctor
	{
		Array<int> a(1);
		if (!assertEqual("param int - size matches", 1, a.size()))
			failed++;
		total++;
		if (!assertEqual("param int - value initialzed to 0", 0, a[0]))
			failed++;
		total++;
	}
	// const int array
	{
		const Array<int> a(1);
		if (!assertEqual("const int - size matches", 1, a.size()))
			failed++;
		total++;
	}
	// char array
	{
		Array<char> a(5);
		if (!assertEqual("char - size matches", 5, a.size()))
			failed++;
		total++;

		if (!assertEqual("char - a[0] init to '\\0'", '\0', a[0]))
			failed++;
		total++;
	}
	// std::string array
	{
		Array<std::string> a(77);
		if (!assertEqual("std::string - size matches", 77, a.size()))
			failed++;
		total++;

		if (!assertEqual("std::string - a[76] init to empty string", "", a[76]))
			failed++;
		total++;
	}
	// float array
	{
		Array<float> a(22);
		if (!assertEqual("float - size matches", 22, a.size()))
			failed++;
		total++;

		if (!assertEqual("float - a[10] init to 0.0f", 0.0f, a[10]))
			failed++;
		total++;
	}

	printSummary(failed, total);
	return (failed);
}
