#include "tests.hpp"
#include "colors.hpp"
#include "Fixed.hpp"
#include <iostream>

int	testMin(void)
{
	printHeader("Min");

	int failed = 0;
	int total = 0;

	// basic ordering
	{
		Fixed a(5);
		Fixed b(10);

		Fixed& result = Fixed::min(a, b);
		total++;
		if (!assertEqualBool("min(5,10) returns a", true, &result == &a))
			failed++;
	}

	// reversed ordering
	{
		Fixed a(10);
		Fixed b(5);

		Fixed& result = Fixed::min(a, b);
		total++;
		if (!assertEqualBool("min(10,5) returns b", true, &result == &b))
			failed++;
	}

	// equal values (tie-break: second argument)
	{
		Fixed a(7);
		Fixed b(7);

		Fixed& result = Fixed::min(a, b);
		total++;
		if (!assertEqualBool("min(equal) returns second", true, &result == &b))
			failed++;
	}

	// negative values
	{
		Fixed a(-3);
		Fixed b(2);

		Fixed& result = Fixed::min(a, b);
		total++;
		if (!assertEqualBool("min(-3,2) returns a", true, &result == &a))
			failed++;
	}

	// float values
	{
		Fixed a(3.5f);
		Fixed b(3.75f);

		Fixed& result = Fixed::min(a, b);
		total++;
		if (!assertEqualBool("min(float) returns a", true, &result == &a))
			failed++;
	}

	// const overload
	{
		const Fixed a(4);
		const Fixed b(9);

		const Fixed& result = Fixed::min(a, b);
		total++;
		if (!assertEqualBool("const min returns a", true, &result == &a))
			failed++;
	}
	printSummary(failed, total);
	return (failed);
}
