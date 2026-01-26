/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:30:53 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/21 18:30:55 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/**
 * @brief Default constructor.
 *
 * Initializes the fixed point value to 0.
 */
Fixed::Fixed() : _fixedPoint(0)
{
	LOG_INFO("Default Constructor called");
	DBG(std::cout << YEL("[DBG] ") << "Default fixedPoint initialized to "
				  << _fixedPoint << '\n';)
}

/**
 * @brief Constructs a Fixed object from an integer.
 * 
 * Converts the integer to fixed-point by shifting it left by the fractional
 * bit count.
 *
 * @param integer Value to convert to fixed-point.
 */
Fixed::Fixed(const int integer) : _fixedPoint(integer << _fractionalBits)
{
	LOG_INFO("Int Constructor called");
	DBG(std::cout << YEL("[DBG] ") << "Int fixedPoint initialized to "
				  << _fixedPoint << '\n';)
}

/**
 * @brief Constructs a Fixed object from a float.
 * 
 * Converts the float to fixed-point by multiplying by 2^fractionalBits and
 * rounding to the nearest integer.
 *
 * @note Bit shifting cannot be done directly on a float, so the float must
 *       be multiplied first, then rounded to an integer.
 *
 * @param floatPoint Value to convert to fixed-point.
 */
Fixed::Fixed(const float floatPoint)
	: _fixedPoint(roundf(floatPoint * (1 << _fractionalBits)))
{
	LOG_INFO("Float Constructor called");
	DBG(std::cout << YEL("[DBG] ") << "Float fixedPoint initialized to "
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
	LOG_INFO("Copy constructor called");
	DBG(std::cout << YEL("[DBG] ") << "Copy fixedPoint initialized to "
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
		LOG_INFO("Copy assignment operator called");
		_fixedPoint = other.getRawBits();
	}
	else
		LOG_WARNING("Self-assignment ignored");
	return (*this);
}

/**
 * @brief Destructor.
 *
 * Prints a log message if in INFO log mode when the object is destroyed.
 */
Fixed::~Fixed()
{
	LOG_INFO("Destructor Called");
}

/**
 * @brief Get the raw fixed-point value.
 *
 * @return The internal fixed-point integer.
 */
int	Fixed::getRawBits(void) const
{
	LOG_DEBUG("getRawBits member function called");
	DBG(std::cout << YEL("[DBG] ") << "Raw bits: " << _fixedPoint << '\n';)

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
