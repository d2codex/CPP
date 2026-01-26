/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:22:04 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/21 18:22:07 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "Logger.hpp"

/**
 * @brief Represents a fixed-point number.
 *
 * Stores the raw fixed-point value and provides accessors.
 */
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


private:
	int					_fixedPoint;
	static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
