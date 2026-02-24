/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:03:46 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/24 16:03:49 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Logger.hpp"
#include <string>
#include <cctype>
#include <climits>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cfloat>
#include <cmath>
#include <limits>
#include <stdexcept>

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{ return (*this); }
ScalarConverter::~ScalarConverter() {}

/*****************************************************************************
 *                              INTERNAL TYPES                               *
 *****************************************************************************/

/**
 * @brief Input types detected from string input.
 */
enum InputType
{
	NONE = -1,
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
};

/*****************************************************************************
 *                              TYPE DETECTION                               *
 *****************************************************************************/

/**
 * @brief Checks if input represents a char literal.
 * Accepts single non-digit chars or quoted chars ('a').
 */
static bool isCharType(const std::string& input)
{
	char c = input[0];
	if (input.length() == 1)
	{
		if (c >= '0' && c <= '9')
			return (false);
		else
			return (true);
	}
	if (input.length() == 3 && (input[0] == '\'' && input[2] == '\''))
		return (true);
	return (false);
}

/**
 * @brief Checks if input represents an integer.
 * Supports optional sign followed by digits.
 */
static bool isIntType(const std::string& input)
{
	size_t len = input.length();
	size_t i = 0;

	if (input[0] == '-' || input[0] == '+')
		i++;
	for (; i < len; i++)
	{
		if (!(input[i] >= '0' && input[i] <= '9'))
			return (false);
	}
	return (true);
}

/**
 * @brief Checks if input represents a float.
 * Accepts literals ending in 'f' and pseudo literals.
 */
static bool isFloatType(const std::string& input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (true);
	if (!input.empty() && input[input.size() - 1] != 'f')
		return (false);
	char* end;
	errno = 0;
	//this only makes sure that double is within range
	std::strtod(input.c_str(), &end);
	if (errno == ERANGE)
		return (false);
	return (end == input.c_str() + input.size() - 1);
}

/**
 * @brief Checks if input represents a double.
 * Requires '.', 'e', or 'E', or matches pseudo literals.
 */
static bool isDoubleType(const std::string& input)
{
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	char* end;
	errno = 0;
	std::strtod(input.c_str(), &end);

	if (end != input.c_str() + input.size())
		return (false);

	if (input.find('.') == std::string::npos &&
		input.find('e') == std::string::npos &&
		input.find('E') == std::string::npos)
		return (false);
	return (true);
}

/*****************************************************************************
 *                            ASSIGNMENT HELPERS                             *
 *****************************************************************************/

/**
 * @brief Assigns int and char from a double value.
 * Sets flags if value is out of int or char range.
 */
static void assignFromDouble(double d, ScalarConverter::Scalar& scalar)
{
    if (d < INT_MIN || d > INT_MAX)
    {
        scalar.impossible |= ScalarConverter::INT_IMPOSSIBLE
                           | ScalarConverter::CHAR_IMPOSSIBLE;
        return;
    }
    scalar.i = static_cast<int>(d);

    if (scalar.i < 0 || scalar.i > 127)
        scalar.impossible |= ScalarConverter::CHAR_IMPOSSIBLE;
    else
    {
        if (scalar.i < 32 || scalar.i > 126)
            scalar.impossible |= ScalarConverter::CHAR_NONDISPLAYABLE;
        scalar.c = static_cast<char>(scalar.i);
    }
}

/**
 * @brief Handles pseudo literals (nan, inf).
 * Sets float/double values and marks char/int impossible.
 * @return true if input is a pseudo literal.
 */
static bool assignPseudoLitterals(const std::string& input, ScalarConverter::Scalar& s)
{
	if (input == "nan" || input == "nanf")
    {
        s.impossible |= ScalarConverter::CHAR_IMPOSSIBLE
                      | ScalarConverter::INT_IMPOSSIBLE;
        s.f = std::numeric_limits<float>::quiet_NaN();
        s.d = std::numeric_limits<double>::quiet_NaN();
        return true;
    }

    if (input == "+inf" || input == "+inff")
    {
        s.impossible |= ScalarConverter::CHAR_IMPOSSIBLE
                      | ScalarConverter::INT_IMPOSSIBLE;
        s.f = std::numeric_limits<float>::infinity();
        s.d = std::numeric_limits<double>::infinity();
        return true;
    }

    if (input == "-inf" || input == "-inff")
    {
        s.impossible |= ScalarConverter::CHAR_IMPOSSIBLE
                      | ScalarConverter::INT_IMPOSSIBLE;
        s.f = -std::numeric_limits<float>::infinity();
        s.d = -std::numeric_limits<double>::infinity();
        return true;
    }

    return false;
}

/*****************************************************************************
 *                            CONVERSION HELPERS                             *
 *****************************************************************************/

/**
 * @brief Converts a char literal to all scalar types.
 */
static void	convertFromChar(const std::string& input, ScalarConverter::Scalar& scalar)
{
	char c = (input.length() == 1) ? input[0] : input[1];
	scalar.c = c;
	scalar.i = static_cast<int>(c);
	scalar.f = static_cast<float>(c);
	scalar.d = static_cast<double>(c);
}

/**
 * @brief Converts an integer string to scalar types.
 * @throws std::out_of_range if int is out of bounds.
 */
static void convertFromInt(const std::string& input, ScalarConverter::Scalar& scalar)
{
	char *end;
	errno = 0;
	double d = strtod(input.c_str(), &end);
	if (errno == ERANGE || d < INT_MIN || d > INT_MAX)
		throw std::out_of_range("Error: Int out of range");
	scalar.f = static_cast<float>(d);
	scalar.d = d;
	assignFromDouble(d, scalar);
}

/**
 * @brief Converts a float string to scalar types.
 * Handles pseudo literals and range validation.
 * @throws std::out_of_range if float is out of bounds.
 */
static void convertFromFloat(const std::string& input, ScalarConverter::Scalar& scalar)
{
	if (assignPseudoLitterals(input, scalar))
		return ;
	std::string s = input;
	if (!s.empty() && s[s.size() - 1] == 'f')
		s.resize(s.size() - 1);
	char *end;
	double d = strtod(s.c_str(), &end);
	if (d < -FLT_MAX || d > FLT_MAX)
		throw std::out_of_range("Error: Float out of range");
	scalar.f = static_cast<float>(d);
	scalar.d = d;
	assignFromDouble(d, scalar);
}

/**
 * @brief Converts a double string to scalar types.
 * Handles pseudo literals and range validation.
 * @throws std::out_of_range if double is out of bounds.
 */
static void convertFromDouble(const std::string& input, ScalarConverter::Scalar& scalar)
{
	if (assignPseudoLitterals(input, scalar))
		return ;
	
	char* end;
	errno = 0;
	double d = strtod(input.c_str(), &end);
	if (errno == ERANGE)
		throw std::out_of_range("Error: double out of range");
	if (d < -FLT_MAX || d > FLT_MAX)
	{
		scalar.impossible |= ScalarConverter::CHAR_IMPOSSIBLE
						   | ScalarConverter::INT_IMPOSSIBLE
						   | ScalarConverter::FLOAT_IMPOSSIBLE;
		scalar.d = d;
		return ;
	}
	scalar.f = static_cast<float>(d);
	scalar.d = d;
	assignFromDouble(d, scalar);
}

/*****************************************************************************
 *                             DISPATCH HELPERS                              *
 *****************************************************************************/

/**
 * @brief Function pointer type for conversion strategies.
 */
typedef void (*ConvertFunction)(const std::string&, ScalarConverter::Scalar&);

/**
 * @brief Array of conversion functions indexed by detected type.
 * Maps each scalar type to its corresponding conversion function,
 * allowing dispatch without conditional branching.
 */
ConvertFunction strategies[] =
{
	convertFromChar,
	convertFromInt,
	convertFromFloat,
	convertFromDouble
};

/**
 * @brief Returns detected input type.
 */
InputType getType(const std::string& input)
{
	if (isCharType(input))
		return (CHAR);
	if (isIntType(input))
		return (INT);
	if (isFloatType(input))
		return (FLOAT);
	if (isDoubleType(input))
		return (DOUBLE);
	return (NONE);
}

/*****************************************************************************
 *                                   OUTPUT                                  *
 *****************************************************************************/

/**
 * @brief Prints scalar values with formatting.
 * Handles impossible and non-displayable cases.
 */
static void printScalar(const ScalarConverter::Scalar& scalar)
{
	if (scalar.impossible & ScalarConverter::CHAR_IMPOSSIBLE)
		std::cout << "Char: impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(scalar.c)))
			std::cout << "Char: Non displayable\n";
	else
			std::cout << "Char: '" << scalar.c << "'\n";

	std::cout << std::fixed << std::setprecision(1);

	if (scalar.impossible & ScalarConverter::INT_IMPOSSIBLE)
		std::cout << "Int: impossible\n";
	else
		std::cout << "Int: " << scalar.i << '\n';

	if (scalar.impossible & ScalarConverter::FLOAT_IMPOSSIBLE)
		std::cout << "Float: impossible\n";
	else
		std::cout << "Float: " << scalar.f << "f\n";
	
	if (scalar.impossible & ScalarConverter::DOUBLE_IMPOSSIBLE)
		std::cout << "Double: impossible\n";
	else
		std::cout << "Double: " << scalar.d << '\n';
}

/*****************************************************************************
 *                              PUBLIC INTERFACE                             *
 *****************************************************************************/

/**
 * @brief Converts input string to scalar representation.
 *
 * Detects type, applies conversion, and prints result.
 *
 * @param input Input string to convert.
 * @return Scalar containing converted values and flags.
 *
 * @throws std::invalid_argument if input is invalid.
 * @throws std::out_of_range if value exceeds limits.
 */
ScalarConverter::Scalar ScalarConverter::convert(const std::string& input)
{
	if (input.empty())
		throw std::invalid_argument("Error: input cannot be empty");

	ScalarConverter::Scalar scalar = {};

	LOG_DEBUG() << "raw input: " << input;

	InputType type = getType(input);
	LOG_DEBUG() << "type: " << type;
	if (type == NONE)
		throw std::invalid_argument("Error: unrecognized type");
	strategies[type](input, scalar);
	printScalar(scalar);
	return (scalar);
}
