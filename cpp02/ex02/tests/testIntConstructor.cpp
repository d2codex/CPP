/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testIntConstructor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:55:59 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/28 16:56:15 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "colors.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <climits>

int testIntConstructor(void)
{
	printHeader("Int Constructor");

	int total = 0;
	int failed = 0;

	int	safety = 1;
	int fractionalBits = 8;
	int	maxSafe = (INT_MAX >> fractionalBits) - safety;
	int	minSafe = (INT_MIN >> fractionalBits) + safety;

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
    Fixed d(maxSafe);
    total++;
    if (!assertEqualInt("maxSafe", maxSafe << fractionalBits, d.getRawBits()))
		{failed++;}

    // Case 5 - near INT_MIN
    Fixed e(minSafe);
    total++;
    if (!assertEqualInt("minSafe", minSafe << fractionalBits, e.getRawBits()))
		{failed++;}

	printSummary(failed, total);
	return (failed);
}
