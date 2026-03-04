/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testDefaultCtor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:17:42 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/04 10:17:44 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "Array.hpp"
#include "Logger.hpp"

int testDefaultCtor()
{
	int failed = 0;
	int	total = 0;

	printHeader("Default Constructor suite");
	//  non-const int array
	{
		Array<int> a;
		if (!assertEqual("int - size matches", 0, a.size()))
			failed++;
		total++;

		bool thrown = false;
		try
		{
			a[0]; // should throw
		}
		catch (const std::out_of_range& e)
		{
			//LOG_ERROR() << e.what();
			thrown = true;
		}
		if (!assertEqual("int - out of bounds a[0] should throw", true, thrown))
			failed++;

		total++;
	}
	// const int array
	{
		const Array<int> a;
		if (!assertEqual("const int - size matches", 0, a.size()))
			failed++;
		total++;

		bool thrown = false;
		try
		{
			a[0]; // should throw
		}
		catch (const std::out_of_range& e)
		{
			//LOG_ERROR() << e.what();
			thrown = true;
		}
		if (!assertEqual("const int - out of bounds a[0] should throw", true, thrown))
			failed++;
		total++;
	}
	// char array
	{
		Array<char> a;
		if (!assertEqual("char - size matches", 0, a.size()))
			failed++;
		total++;
	}
	// std::string array
	{
		Array<std::string> a;
		if (!assertEqual("std::string - size matches", 0, a.size()))
			failed++;
		total++;
	}
	// float array
	{
		Array<float> a;
		if (!assertEqual("float - size matches", 0, a.size()))
			failed++;
		total++;
	}

	printSummary(failed, total);
	return (failed);
}
