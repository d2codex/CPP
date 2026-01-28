#include "tests.hpp"
#include "colors.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <climits>

int	testToFloat(void)
{
	printHeader("To Float");
	
	int	failed = 0;
	int total = 0;

	// Case 1: normal integer
	Fixed a(10);
	total++;
	if (!assertEqualFloat("normal",
				static_cast<float>(10),
				a.toFloat()))
	{failed++;}

	// Case 2: positive float
	Fixed b(42.42f);
	total++;
	if (!assertEqualFloat("positive float",
				static_cast<float>(42.42f),
				b.toFloat()))
	{failed++;}

	// Case 3: negative float
	Fixed c(-10.5f);
	total++;
	if (!assertEqualFloat("negative float",
				static_cast<float>(-10.5f),
				c.toFloat()))
	{failed++;}

	// Case 4: zero
	Fixed d(0);
	total++;
	if (!assertEqualFloat("zero",
				static_cast<float>(0),
				d.toFloat()))
	{failed++;}

	// Case 5: smallest exact fraction (1 / 256 with 8 fractional bits)
	Fixed e(1.0f / 256);
	total++;
	if (!assertEqualFloat("small fraction",
				static_cast<float>(1.0f / 256),
				e.toFloat()))
	{failed++;}

	int			fractionalBits = 8;
	const int scale = 1 << fractionalBits;
	const int	safetyMargin = 1;
	const int	approxMax = (INT_MAX / scale) - safetyMargin;
	const int	approxMin = (INT_MIN / scale) + safetyMargin;

	// Case 6: approximate max
	Fixed f(approxMax);
	total++;
	if (!assertEqualFloat("approximate max",
				static_cast<float>(approxMax),
				f.toFloat()))
	{failed++;}

	// Case 7: min allowed
	Fixed g(approxMin);
	total++;
	if (!assertEqualFloat("approximate min",
				static_cast<float>(approxMin),
				g.toFloat()))
	{failed++;}

	printSummary(failed, total);
	return (failed);
}
