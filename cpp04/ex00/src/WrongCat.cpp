/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:37:56 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 10:53:22 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

/** @brief Constructs a WrongCat with type set to "WrongCat". */
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	LOG_INFO() << "WrongCat default constructor called";
	LOG_DEBUG() << "Animal type " << _type;
}

/**
 * @brief Copy constructs a WrongCat.
 * @param other The WrongCat to copy from.
 */
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	LOG_INFO() << "WrongCat copy constructor called";
	LOG_DEBUG() << "Animal type " << _type;
}

/**
 * @brief Assigns another WrongCat to this one.
 * @param other The WrongCat to assign from.
 * @return Reference to this WrongCat.
 */
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	else
		LOG_WARNING() << "WrongCat self-assignment ignored";
	LOG_INFO() << "WrongCat assignment constructor called";
	LOG_DEBUG() << "Animal type " << _type;
	return (*this);
}

/** @brief Emits the WrongCat sound. */
void WrongCat::makeSound() const
{
	std::cout << "meeeeeh\n";
	LOG_DEBUG() << "Animal type " << _type;
}

/** @brief Destroys the WrongCat instance. */
WrongCat::~WrongCat()
{
	LOG_INFO() << "WrongCat destructor called";
}
