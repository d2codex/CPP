/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:22:04 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/21 21:02:46 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "Logger.hpp"

class Fixed
{
public:
	Fixed();
	Fixed(const int integer);
	Fixed(const float floatPoint);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	// comparison operators ( > < >= <= == !=)
	bool operator>(const Fixed& rightSide) const;
	bool operator<(const Fixed& rightSide) const;
	bool operator>=(const Fixed& rightSide) const;
	bool operator<=(const Fixed& rightSide) const;
	bool operator==(const Fixed& rightSide) const;
	bool operator!=(const Fixed& rightSide) const;
	
	// arithmetic operations (+ - * /)
	Fixed operator+(const Fixed& rightSide) const;
	Fixed operator-(const Fixed& rightSide) const;
	Fixed operator*(const Fixed& rightSide) const;
	Fixed operator/(const Fixed& rightSide) const;

	// increment/decrement (pre and post for each)
	
	// static overload functions


private:
	int					_fixedPoint;
	static const int	_fractionalBits = 8;
};

// assignment operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
