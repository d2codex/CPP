/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testSwap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:39:32 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/01 19:39:33 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "whatever.hpp"
#include <climits>
#include <ostream>

struct Point
{
	int x;
	int y;
};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int	testSwap()
{
	int	failed = 0;
	int	total = 0;

	printHeader("Swap suite");
	// test int positive
	{
		int a = 2;
		int b = 3;
		::swap(a, b);
		if (!assertEqual("int (2, 3) confirm a", 3, a))
			failed++;
		if (!assertEqual("int (2, 3) confirm b", 2, b))
			failed++;
		total++;
	}
	// test int negative
	{
		int a = -2;
		int b = -3;
		::swap(a, b);
		if (!assertEqual("int (-2, -3) confirm a", -3, a))
			failed++;
		if (!assertEqual("int (-2, -3) confirm b", -2, b))
			failed++;
		total++;
	}
	// test int zero / INT_MAX
	{
		int a = 0;
		int b = INT_MAX;
		::swap(a, b);
		if (!assertEqual("int (0, INT_MAX) confirm a", INT_MAX, a))
			failed++;
		if (!assertEqual("int (0, INT_MAX) confirm b", 0, b))
			failed++;
		total++;
	}
	// test float
	{
		float a = -2.f;
		float b = 25.00f;
		::swap(a, b);
		if (!assertEqual("float (-2.f, 25.00) confirm a", 25.00f, a))
			failed++;
		if (!assertEqual("float (-2.f, 25.00) confirm b", -2.f, b))
			failed++;
		total++;
	}
	// test double
	{
		double a = 10.0123456789;
		double b = -25.00;
		::swap(a, b);
		if (!assertEqual("double (10.0123456789, -25.00) confirm a", -25.00, a))
			failed++;
		if (!assertEqual("double (10.0123456789, -25.00) confirm b", 10.0123456789, b))
			failed++;
		total++;
	}
	// test char
	{
		char a = 'z';
		char b = 'm';
		::swap(a, b);
		if (!assertEqual("char (z, m) confirm a", 'm', a))
			failed++;
		if (!assertEqual("char (z, m) confirm b", 'z', b))
			failed++;
		total++;
	}
	// test bool
	{
		bool a = true;
		bool b = false;
		::swap(a, b);
		if (!assertEqual("bool (true, false) confirm a", false, a))
			failed++;
		if (!assertEqual("bool (true, false) confirm b", true, b))
			failed++;
		total++;
	}
	// test std::string
	{
		std::string a = "hello";
		std::string b = "world";
		::swap(a, b);
		if (!assertEqual("std::string (hello, world) confirm a", "world", a))
			failed++;
		if (!assertEqual("std::string (hello, world) confirm b", "hello", b))
			failed++;
		total++;
	}
	// test struct
	{
		Point a = {1, 2};
		Point b = {3, 4};
		::swap(a, b);
		if (!assertEqual("struct a(1,2), b(3,4) confirm a.x", 3, a.x))
			failed++;
		if (!assertEqual("struct a(1,2), b(3,4) confirm a.y", 4, a.y))
			failed++;
		if (!assertEqual("struct a(1,2), b(3,4) confirm b.x", 1, b.x))
			failed++;
		if (!assertEqual("struct a(1,2), b(3,4) confirm b.y", 2, b.y))
			failed++;
		total++;
	}
	printSummary(failed, total);
	return (failed);
}
