/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:30:53 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/29 22:25:43 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "colors.hpp"
#include <iostream>
#include <climits>
#include <sstream>
#include <stdexcept>
#include <cmath>

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

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
 * @brief Construct a Fixed from an int, with overflow protection.
 *
 * Converts an integer to fixed-point representation. Throws std::out_of_range
 * if integer is outside the allowed range [MIN_SAFE, MAX_SAFE].
 *
 * @param integer The integer value to convert
 * @throws std::out_of_range if integer exceeds safe limits
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
 * @brief Construct a Fixed from a float, with overflow protection.
 *
 * Converts a float to fixed-point representation. Throws std::out_of_range
 * if floatPoint is outside the allowed range [MIN_SAFE, MAX_SAFE].
 *
 * @param floatPoint The float value to convert
 * @throws std::out_of_range if floatPoint exceeds safe limits
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

/*****************************************************************************
 *                             GETTER / SETTER                               *
 *****************************************************************************/

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

/*****************************************************************************
 *                                CONVERSIONS                                *
 *****************************************************************************/

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

/*****************************************************************************
 *                            COMPARISON OPERATORS                           *
 *****************************************************************************/

/**
 * @brief Checks if this Fixed is greater than rhs.
 * @param rhs The Fixed to compare against.
 * @return True if this > rhs, false otherwise.
 */
bool Fixed::operator>(const Fixed& rhs) const
{
	return (_fixedPoint > rhs._fixedPoint);
}

/**
 * @brief Checks if this Fixed is less than rhs.
 * @param rhs The Fixed to compare against.
 * @return True if this < rhs, false otherwise.
 */
bool Fixed::operator<(const Fixed& rhs) const
{
	return (_fixedPoint < rhs._fixedPoint);
}

/**
 * @brief Checks if this Fixed is greater than or equal to rhs.
 * @param rhs The Fixed to compare against.
 * @return True if this >= rhs, false otherwise.
 */
bool Fixed::operator>=(const Fixed& rhs) const
{
	return (_fixedPoint >= rhs._fixedPoint);
}

/**
 * @brief Checks if this Fixed is less than or equal to rhs.
 * @param rhs The Fixed to compare against.
 * @return True if this <= rhs, false otherwise.
 */
bool Fixed::operator<=(const Fixed& rhs) const
{
	return (_fixedPoint <= rhs._fixedPoint);
}

/**
 * @brief Checks if this Fixed is equal to rhs.
 * @param rhs The Fixed to compare against.
 * @return True if this == rhs, false otherwise.
 */
bool Fixed::operator==(const Fixed& rhs) const
{
	return (_fixedPoint == rhs._fixedPoint);
}

/**
 * @brief Checks if this Fixed is not equal to rhs.
 * @param rhs The Fixed to compare against.
 * @return True if this != rhs, false otherwise.
 */
bool Fixed::operator!=(const Fixed& rhs) const
{
	return (_fixedPoint != rhs._fixedPoint);
}

/*****************************************************************************
 *                            ARITHMETIC OPERATORS                           *
 *****************************************************************************/

/**
 * @brief Adds two Fixed-point numbers with overflow check.
 * @param rhs The Fixed to add.
 * @return A new Fixed representing the sum.
 * @throws std::overflow_error if the addition exceeds INT_MAX/INT_MIN.
 */
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

/**
 * @brief Subtracts rhs from this Fixed-point number with overflow check.
 * @param rhs The Fixed to subtract.
 * @return A new Fixed representing the difference.
 * @throws std::overflow_error if the subtraction exceeds INT_MAX/INT_MIN.
 */
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

/**
 * @brief Multiplies two Fixed-point numbers with overflow check.
 * @param rhs The Fixed to multiply with.
 * @return A new Fixed representing the product.
 * @throws std::overflow_error if the multiplication exceeds INT_MAX/INT_MIN.
 */
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

/**
 * @brief Divides this Fixed-point number by rhs with overflow and zero check.
 * @param rhs The Fixed divisor.
 * @return A new Fixed representing the quotient.
 * @throws std::domain_error if rhs is zero.
 * @throws std::overflow_error if the division exceeds INT_MAX/INT_MIN.
 */
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

/*****************************************************************************
 *                      INCREMENT / DECREMENT OPERATORS                      *
 *****************************************************************************/

/**
 * @brief Pre-increment: increases Fixed by one fractional bit, returns *this.
 * @return Reference to the incremented Fixed object.
 * @throws std::overflow_error if increment would exceed MAX_SAFE.
 */
Fixed& Fixed::operator++()
{
	if (_fixedPoint >= MAX_SAFE << _fractionalBits)
	{
		LOG_ERROR(red("Incrementing this value would overflow"));
		throw std::overflow_error("Increment overflow");
	}
	++_fixedPoint;
	return (*this);
}

/**
 * @brief Post-increment: increases Fixed by one fractional bit, returns old
 * value.
 * @return A Fixed object containing the original value before increment.
 */
Fixed Fixed::operator++(int)
{
	Fixed oldValue(*this);
	_fixedPoint++;

	return (oldValue);
}

/**
 * @brief Pre-decrement: decreases Fixed by one fractional bit, returns *this.
 * @return Reference to the decremented Fixed object.
 * @throws std::overflow_error if decrement would go below MIN_SAFE.
 */
Fixed& Fixed::operator--()
{
	if(_fixedPoint < MIN_SAFE >> _fractionalBits)
	{
		LOG_ERROR("decrementing this value would overflow");
		throw std::overflow_error("decrement overflow");
	}
	--_fixedPoint;
	return (*this);
}

/**
 * @brief Post-decrement: decreases Fixed by one fractional bit, returns old
 * value.
 * @return A Fixed object containing the original value before decrement.
 */
Fixed Fixed::operator--(int)
{
	Fixed oldValue(*this);
	_fixedPoint--;

	return (oldValue);
}

/*****************************************************************************
 *                                 MIN / MAX                                 *
 *****************************************************************************/

/**
 * @brief Returns the smaller of two Fixed numbers (non-const).
 * @param n1 First Fixed object.
 * @param n2 Second Fixed object.
 * @return Reference to the smaller Fixed. First wins if equal.
 */
Fixed& Fixed::min(Fixed& n1, Fixed& n2)
{
	return (n2 < n1 ? n2 : n1);
}

/**
 * @brief Returns the larger of two Fixed numbers (non-const).
 * @param n1 First Fixed object.
 * @param n2 Second Fixed object.
 * @return Reference to the larger Fixed. First wins if equal.
 */
Fixed& Fixed::max(Fixed& n1, Fixed& n2)
{
	return (n2 > n1 ? n2 : n1);
}

/**
 * @brief Returns the smaller of two Fixed numbers (const).
 * @param n1 First Fixed object.
 * @param n2 Second Fixed object.
 * @return Const reference to the smaller Fixed. First wins if equal.
 */
const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2)
{
	return (n2 < n1 ? n2 : n1);
}

/**
 * @brief Returns the larger of two Fixed numbers (const).
 * @param n1 First Fixed object.
 * @param n2 Second Fixed object.
 * @return Const reference to the larger Fixed. First wins if equal.
 */
const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2)
{
	return (n2 > n1 ? n2 : n1);
}

/*****************************************************************************
 *                          INPUT / OUTPUT OPERATORS						 *
 *****************************************************************************/

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
