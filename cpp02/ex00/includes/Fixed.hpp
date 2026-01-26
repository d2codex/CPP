/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:18:05 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:17 by diade-so         ###   ########.fr       */
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
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_fixedPoint;
	static const int	_fractionalBits = 8;
};

#endif
