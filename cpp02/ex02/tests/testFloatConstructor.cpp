/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testFloatConstructor.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:55:49 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/28 16:55:51 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	const int scale = 1 << fractionalBits;
	int	failed = 0;
	int	total = 0;

	 // Case 1 - normal
    Fixed normal(42.42f);
    total++;
    if (!assertEqualInt("normal",
                        roundf(42.42f * scale),
                        normal.getRawBits()))
		{failed++;}

    // Case 2 - zero
    Fixed zero(0.0f);
    total++;
    if (!assertEqualInt("zero",
                        roundf(0.0f * scale),
                        zero.getRawBits()))
		{failed++;}

    // Case 3 - negative
    Fixed negative(-42.42f);
    total++;
    if (!assertEqualInt("negative",
                        roundf(-42.42f * scale),
                        negative.getRawBits()))
		{failed++;}

	const int	safetyMargin = 1;
	const int	approxMax = (INT_MAX / scale) - safetyMargin;
	const int	approxMin = (INT_MIN / scale) + safetyMargin;

    // Case 4 - approximate max
    Fixed max(approxMax);
    total++;
    if (!assertEqualInt("approxMax",
                        roundf(approxMax * scale),
                        max.getRawBits()))
		{failed++;}

    // Case 5 - approximate min
    Fixed min(approxMin);
    total++;
    if (!assertEqualInt("approxMin",
                        roundf(approxMin * scale),
                        min.getRawBits()))
		{failed++;}

	printSummary(failed, total);
	return (failed);
}
