#include "tests.hpp"
#include "colors.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <climits>

int testFloatConstructor(void)
{
	printHeader("Float Constructor");

	int fractionalBits = 8;
	int	failed = 0;
	int	total = 0;

	 // Case 1 - normal
    Fixed normal(42.42f);
    total++;
    if (!assertEqualInt("normal",
                        roundf(42.42f * (1 << fractionalBits)),
                        normal.getRawBits()))
		{failed++;}

    // Case 2 - zero
    Fixed zero(0.0f);
    total++;
    if (!assertEqualInt("zero",
                        roundf(0.0f * (1 << fractionalBits)),
                        zero.getRawBits()))
		{failed++;}

    // Case 3 - negative
    Fixed negative(-42.42f);
    total++;
    if (!assertEqualInt("negative",
                        roundf(-42.42f * (1 << fractionalBits)),
                        negative.getRawBits()))
		{failed++;}

    // Case 4 - allowed max
	const float maxAllowed = (float)INT_MAX / (1 << fractionalBits);
    Fixed max(maxAllowed);
    total++;
    if (!assertEqualInt("maxAllowed",
                        roundf(maxAllowed * (1 << fractionalBits)),
                        max.getRawBits()))
		{failed++;}

    // Case 5 - allowed min
	const float minAllowed = (float)INT_MIN / (1 << fractionalBits);
    Fixed min(minAllowed);
    total++;
    if (!assertEqualInt("minAllowed",
                        roundf(minAllowed * (1 << fractionalBits)),
                        min.getRawBits()))
		{failed++;}

	printSummary("Float Constructor", failed, total);
	return (failed);
}
