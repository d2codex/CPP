#include "tests.hpp"
#include "colors.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <climits>
//#include <cmath>

int testIntConstructor(void)
{
	printHeader("Int Constructor");

	int fractionalBits = 8;
	int total = 0;
	int failed = 0;

	// Case 1
    Fixed a(5);
    total++;
    if (!assertEqualInt("normal", 5 << fractionalBits, a.getRawBits()))
		{failed++;}

    // Case 2
    Fixed b(0);
    total++;
    if (!assertEqualInt("zero", 0 << fractionalBits, b.getRawBits()))
		{failed++;}

    // Case 3
    Fixed c(-5);
    total++;
    if (!assertEqualInt("negative", -5 << fractionalBits, c.getRawBits()))
		{failed++;}

	// Case 4 - near INT_MAX
	int maxAllowed = INT_MAX >> fractionalBits;
    Fixed d(maxAllowed);
    total++;
    if (!assertEqualInt("maxAllowed", maxAllowed << fractionalBits, d.getRawBits()))
		{failed++;}

    // Case 5 - near INT_MIN
	int minAllowed = INT_MIN >> fractionalBits;
    Fixed e(minAllowed);
    total++;
    if (!assertEqualInt("minAllowed", minAllowed << fractionalBits, e.getRawBits()))
		{failed++;}

	printSummary(failed, total);
	return (failed);
}
