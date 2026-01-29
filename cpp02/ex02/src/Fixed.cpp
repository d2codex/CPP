/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:30:53 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/28 21:51:45 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "colors.hpp"
#include <iostream>
#include <climits>
#include <sstream>
#include <stdexcept>
#include <cmath>

/**
 * @brief Default constructor.
 *
 * Initializes the fixed point value to 0.
 */
Fixed::Fixed() : _fixedPoint(0)
{
	LOG_DEBUG("Default Constructor called");
	DBG(std::cout << yel("[DBG] ") << "Default fixedPoint initialized to "
				  << _fixedPoint << '\n';)
}

/**
 * @brief Constructs a Fixed object from an integer.
 * 
 * Converts the integer to fixed-point by shifting left by `fractionalBits`.
 * Checks for overflow before conversion.
 *
 * @param integer Value to convert.
 * @throws std::out_of_range if the integer is outside the allowed range.
 */
Fixed::Fixed(const int integer)
{
	if (integer > MAX_SAFE || integer < MIN_SAFE)
	{
		std::ostringstream oss;
        oss << RED "Int overflow: allowed range is "
            << MIN_SAFE << " to " << MAX_SAFE << RESET;

		LOG_ERROR(oss.str());
        throw std::out_of_range("Int overflow");
	}

	_fixedPoint = integer << _fractionalBits;

	LOG_DEBUG("Int Constructor called");
	DBG(std::cout << yel("[DBG] ") << "Int fixedPoint initialized to "
				  << _fixedPoint << '\n';)
}

/**
 * @brief Constructs a Fixed object from a float.
 * 
 * Converts the float to fixed-point by multiplying by 2^fractionalBits and
 * rounding to the nearest integer. Performs an overflow check to ensure the
 * resulting fixed-point value fits within the limits of an int.
 *
 * @note Bit shifting cannot be done directly on a float, so the float must
 *       be multiplied first, then rounded to an integer.
 * @note The constructor uses a safety margin to compute approximate maximum
 *       and minimum float values that can safely be converted without 
 *       overflowing the underlying integer storage.
 *
 * @param floatPoint Value to convert to fixed-point.
 * @throws std::out_of_range if the float is outside the safe range and would
 *         cause an integer overflow after conversion.
 */
Fixed::Fixed(const float floatPoint)
{
	if (floatPoint > MAX_SAFE || floatPoint < MIN_SAFE)
	{
		std::ostringstream oss;
		oss << RED "Float overflow: allowed range is "
			<< MIN_SAFE << " to " << MAX_SAFE;

		LOG_ERROR(oss.str());
		throw std::out_of_range("Float overflow");
	}

	const int scale = 1 << _fractionalBits;
	_fixedPoint = static_cast<int>(roundf(floatPoint * scale));

	LOG_DEBUG("Float Constructor called");
	DBG(std::cout << yel("[DBG] ") << "Float fixedPoint initialized to "
				  << _fixedPoint << '\n';)
}

/**
 * @brief Copy constructor.
 *
 * Copies the value from another Fixed instance. The initializer list
 * version is commented out to match subject output, but it is more
 * efficient. Using `*this = other;` calls the copy assignment operator.
 */
Fixed::Fixed(const Fixed& other) //: _fixedPoint(other._fixedPoint)
{
	LOG_DEBUG("Copy constructor called");
	DBG(std::cout << yel("[DBG] ") << "Copy fixedPoint initialized to "
				  << other._fixedPoint << '\n';)
	
	*this = other;
}

/**
 * @brief Copy assignment operator.
 *
 * Copies the raw fixed-point value from another object. Self-assignment
 * is ignored.
 *
 * @return Reference to *this.
 */
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		LOG_DEBUG("Copy assignment operator called");
		_fixedPoint = other.getRawBits();
	}
	else
		LOG_WARNING("Self-assignment ignored");
	return (*this);
}

/**
 * @brief Destructor.
 *
 * Prints a log message if in DEBUG log mode when the object is destroyed.
 */
Fixed::~Fixed()
{
	LOG_DEBUG("Destructor Called");
}

/**
 * @brief Get the raw fixed-point value.
 *
 * @return The internal fixed-point integer.
 */
int	Fixed::getRawBits(void) const
{
	LOG_DEBUG("getRawBits member function called");
	DBG(std::cout << yel("[DBG] ") << "Raw bits: " << _fixedPoint << '\n';)

	return (_fixedPoint);
}

/**
 * @brief Set the raw fixed-point value.
 *
 * @param raw The value to store in the fixed-point member.
 */
void	Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}

/**
 * @brief Converts the fixed-point value to a float.
 *
 * The raw fixed-point integer is divided by 2^fractionalBits.
 * A cast to float is required to preserve the fractional part.
 *
 * @return Floating-point representation.
 */
float	Fixed::toFloat(void) const
{
	return ((float)_fixedPoint / (1 << _fractionalBits));
}

/**
 * @brief Converts the fixed-point value to an integer.
 *
 * The raw fixed-point integer is shifted right by the fractional bit count.
 * This discards the fractional part (truncation).
 *
 * @return Integer representation.
 */
int	Fixed::toInt(void) const
{
	return (_fixedPoint >> _fractionalBits);
}

/**
 * @brief Outputs the floating-point representation of a Fixed object.
 *
 * Overloads the insertion operator to print the fixed-point value as a
 * float.
 *
 * @note This overload is called when a Fixed object is on the right side
 *       of the `<<` operator.
 *
 * @param os Output stream to write to.
 * @param fixed Fixed object to output.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

// arithmetic Operators

Fixed Fixed::operator+(const Fixed& rhs) const
{
	long tmp = static_cast<long>(this->getRawBits())
			 + static_cast<long>(rhs.getRawBits());

	if (tmp > INT_MAX || tmp < INT_MIN)
	{
		LOG_ERROR("Fixed-point addition overflow");
		throw std::overflow_error("addition overflow");
	}

	Fixed result;
	result.setRawBits(static_cast<int>(tmp));
	return (result);
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	long tmp = static_cast<long>(this->getRawBits())
			 - static_cast<long>(rhs.getRawBits());

	if (tmp > INT_MAX || tmp < INT_MIN)
	{
		LOG_ERROR("Fixed-point subtraction overflow");
		throw std::overflow_error("subtraction overflow");
	}

	Fixed result;
	result.setRawBits(tmp);
	return (result);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	long long tmp = static_cast<long long>(this->getRawBits())
				  * static_cast<long long>(rhs.getRawBits());
	
	tmp = tmp >> _fractionalBits;

	if (tmp > INT_MAX || tmp < INT_MIN)
	{
		LOG_ERROR(red("Fixed-point multiplication overflow"));
		throw std::overflow_error("Multiplication overflow");
	}

	Fixed result;
	result.setRawBits(static_cast<int>(tmp));
	return (result);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	if (rhs.getRawBits() == 0)
	{
		LOG_ERROR(red("Cannot divide by 0"));
		throw std::domain_error("divison by 0");
	}
	long long tmp = static_cast<long long>(this->getRawBits()) << _fractionalBits;
	tmp /= static_cast<long long>(rhs.getRawBits());

	if (tmp > INT_MAX || tmp < INT_MIN)
	{
		LOG_ERROR(red("Division overflow"));
		throw std::overflow_error("division overflow");
	}
	Fixed result;
	result.setRawBits(tmp);
	return (result);
}

