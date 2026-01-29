/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:22:04 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/28 21:27:34 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Logger.hpp"
#include <climits>

/**
 * @brief Represents a fixed-point number.
 *
 * Stores the raw fixed-point value and provides accessors.
 */
class Fixed
{
public:
	// constructors
	Fixed();
	Fixed(const int integer);
	Fixed(const float floatPoint);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	// getter / setter
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// conversion
	float	toFloat(void) const;
	int		toInt(void) const;

	// comparison
	bool operator>(const Fixed& rhs) const;
	bool operator<(const Fixed& rhs) const;
	bool operator>=(const Fixed& rhs) const;
	bool operator<=(const Fixed& rhs) const;
	bool operator==(const Fixed& rhs) const;
	bool operator!=(const Fixed& rhs) const;

	// arithmetic
	Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

	// increment / decrement
	Fixed& operator++();    // ++prefix //modifies the object &
    Fixed operator++(int);  // postfix++
    Fixed& operator--();    // --prefix
    Fixed operator--(int);  // postfix --

	// min / max
	static Fixed& min(Fixed& n1, Fixed& n2);
	static Fixed& max(Fixed& n1, Fixed& n2);
	static const Fixed& min(const Fixed& n1, const Fixed& n2);
	static const Fixed& max(const Fixed& n1, const Fixed& n2);
	

private:
	int					_fixedPoint;
	static const int	_fractionalBits = 8;
	static const int	SAFETY_MARGIN = 1;

	static const int	MAX_SAFE = (INT_MAX >> _fractionalBits) - SAFETY_MARGIN;
	static const int	MIN_SAFE = (INT_MIN >> _fractionalBits) + SAFETY_MARGIN;

};

// I/O Operators
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
