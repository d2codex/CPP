#include "tests.hpp"
#include "colors.hpp"
#include "Fixed.hpp"
#include <iostream>

int testMax(void)
{
	printHeader("max()");

	int failed = 0;
	int total = 0;

	// basic ordering
	{
		Fixed a(5);
		Fixed b(10);

		Fixed& result = Fixed::max(a, b);
		total++;
		if (!assertEqualBool("max(5,10) returns b", true, &result == &b))
			failed++;
	}

	// reversed ordering
	{
		Fixed a(10);
		Fixed b(5);

		Fixed& result = Fixed::max(a, b);
		total++;
		if (!assertEqualBool("max(10,5) returns a", true, &result == &a))
			failed++;
	}

	// equal values (tie-break: second argument)
	{
		Fixed a(7);
		Fixed b(7);

		Fixed& result = Fixed::max(a, b);
		total++;
		if (!assertEqualBool("max(equal) returns second", true, &result == &b))
			failed++;
	}

	// negative values
	{
		Fixed a(-3);
		Fixed b(2);

		Fixed& result = Fixed::max(a, b);
		total++;
		if (!assertEqualBool("max(-3,2) returns b", true, &result == &b))
			failed++;
	}

	// float values
	{
		Fixed a(3.5f);
		Fixed b(3.75f);

		Fixed& result = Fixed::max(a, b);
		total++;
		if (!assertEqualBool("max(float) returns b", true, &result == &b))
			failed++;
	}

	// const overload
	{
		const Fixed a(4);
		const Fixed b(9);

		const Fixed& result = Fixed::max(a, b);
		total++;
		if (!assertEqualBool("const max returns b", true, &result == &b))
			failed++;
	}

	printSummary(failed, total);
	return failed;
}
