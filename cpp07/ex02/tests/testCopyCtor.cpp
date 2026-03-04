/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testCopyCtor.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:17:35 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/04 10:17:37 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Array.hpp"
#include "Logger.hpp"

int testCopyCtor()
{
	int failed = 0;
	int	total = 0;

	printHeader("Copy Constructor suite");
	// non const int parameterized ctor
	{
		Array<int> a(1);
		a[0] = 42;
		Array<int> b(a);

		if (!assertEqual("int (nconst/nconst) - copy size", a.size(), b.size()))
			failed++;
		total++;

		if (!assertEqual("int (nconst/nconst) - copy value", a[0], b[0]))
			failed++;
		total++;

		if (!assertEqual("int (nconst/nconst) - deep copy", 42, b[0]))
			failed++;
		total++;

		b[0] = 100;

		if (!assertEqual("modifingy b does not modify a", 42, a[0]))
			failed++;
		total++;
	}
	// const char array - cannot modify contents
	// copy can only be done at construction time
	// cannot assign a = b; compile error
	{
		const Array<char> a(3);
		const Array<char> b(a);

		if (!assertEqual("char (const/const) - copy size", a.size(), b.size()))
			failed++;
		total++;

		if (!assertEqual("char (const/const) - copy value", a[2], b[2]))
			failed++;
		total++;
	}
	// std string array non const/ const
	{
		Array<std::string> a(1);
		a[0] = "hello world";
		const Array<std::string> b(a);

		if (!assertEqual("std::string (nconst/const) - copy size", a.size(), b.size()))
			failed++;
		total++;

		if (!assertEqual("std::string (nconst/const) - copy value", a[0], b[0]))
			failed++;
		total++;

		if (!assertEqual("std::string (nconst/const) - deep copy", "hello world", b[0]))
			failed++;
		total++;
	}

	printSummary(failed, total);
	return (failed);
}
