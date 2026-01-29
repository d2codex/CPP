/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testComparisons.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:26:23 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/29 22:26:29 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "colors.hpp"
#include "Fixed.hpp"
#include <iostream>

int	testComparisons(void)
{
	printHeader("Comparisons");

	int failed = 0;
	int total = 0;

	{
		Fixed a(3);
		Fixed b(5);

		total++;	
		if (!assertEqualBool("3 > 5", false, a > b))
			{failed++;}
		
		total++;	
		if (!assertEqualBool("3 < 5", true, a < b))
			{failed++;}

		total++;	
		if (!assertEqualBool("5 == 5", true, Fixed(5) == Fixed(5)))
			{failed++;}

		total++;	
		if (!assertEqualBool("5 != 5", false, Fixed(5) != Fixed(5)))
			{failed++;}

		total++;	
		if (!assertEqualBool("5 >= 5", true, Fixed(5) >= Fixed(5)))
			{failed++;}

		total++;	
		if (!assertEqualBool("7 != 5", true, Fixed(7) != Fixed(5)))
			{failed++;}

		total++;	
		if (!assertEqualBool("-7.0f > 5", false, Fixed(-7.0f) > Fixed(5)))
			{failed++;}

		total++;	
		if (!assertEqualBool("-7.0f < 5.23f", true, Fixed(-7.0f) < Fixed(5.23f)))
			{failed++;}
	}

	printSummary(failed, total);
	return (failed);
}
