/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:17:59 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:01 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/**
 * @brief Default constructor.
 *
 * Initializes the fixed point value to 0.
 */
Fixed::Fixed() : _fixedPoint(0)
{
	LOG_DEBUG("Default Constructor called");
	DBG(std::cout << YEL("[DBG] ") << "Default fixedPoint initialized to "
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
