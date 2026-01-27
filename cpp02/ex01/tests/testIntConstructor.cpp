#include "tests.hpp"
#include "colors.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <climits>
//#include <cmath>

int testIntConstructor()
{
	int fractionalBits = 8;
	printHeader("Int Constructor");

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
	int allowedMax = INT_MAX >> fractionalBits;
    Fixed d(allowedMax);
    total++;
    if (!assertEqualInt("maxAllowed", allowedMax << fractionalBits, d.getRawBits()))
		{failed++;}

    // Case 5 - near INT_MIN
	int allowedMin = INT_MIN >> fractionalBits;
    Fixed e(allowedMin);
    total++;
    if (!assertEqualInt("minAllowed", allowedMin << fractionalBits, e.getRawBits()))
		{failed++;}

	printSummary("Int Constructor", failed, total);
	return (failed);
}
