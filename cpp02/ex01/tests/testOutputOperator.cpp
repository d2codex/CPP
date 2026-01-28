/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testOutputOperator.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:56:25 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/28 16:56:27 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "colors.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <sstream>
#include <string>

int testOutputOperator(void)
{
	printHeader("operator<<");

	int failed = 0;
	int total = 0;

	/* ============================= */
	/*   INT CONSTRUCTOR TESTS       */
	/* ============================= */

	// Case 1: normal integer
	{
		Fixed a(10);
		std::ostringstream oss;
		oss << a;
		float outVal;
		std::istringstream iss(oss.str());
		iss >> outVal;

		total++;
		if (!assertEqualFloat("int: normal", 10.0f, outVal))
			{ failed++; }
	}

	// Case 2: negative integer
	{
		Fixed a(-10);
		std::ostringstream oss;
		oss << a;
		float outVal;
		std::istringstream iss(oss.str());
		iss >> outVal;

		total++;
		if (!assertEqualFloat("int: negative", -10.0f, outVal))
			{ failed++; }
	}

	// Case 3: zero
	{
		Fixed a(0);
		std::ostringstream oss;
		oss << a;
		float outVal;
		std::istringstream iss(oss.str());
		iss >> outVal;

		total++;
		if (!assertEqualFloat("int: zero", 0.0f, outVal))
			{ failed++; }
	}

	/* ============================= */
	/*   FLOAT CONSTRUCTOR TESTS     */
	/* ============================= */

	// Case 4: positive float
	{
		const float input = 42.42f;
		Fixed b(input);
		std::ostringstream oss;
		oss << b;
		float outVal;
		std::istringstream iss(oss.str());
		iss >> outVal;

		total++;
		if (!assertEqualFloat("float: positive", input, outVal))
			{ failed++; }
	}

	// Case 5: negative float
	{
		const float input = -10.5f;
		Fixed b(input);
		std::ostringstream oss;
		oss << b;
		float outVal;
		std::istringstream iss(oss.str());
		iss >> outVal;

		total++;
		if (!assertEqualFloat("float: negative", input, outVal))
			{ failed++; }
	}

	printSummary(failed, total);
	return failed;
}
