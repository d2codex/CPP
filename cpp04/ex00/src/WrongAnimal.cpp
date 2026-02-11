/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:37:53 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 10:52:10 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

/** @brief Constructs a WrongAnimal with default type. */
WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	LOG_INFO() << "WrongAnimal default constructor called";
	LOG_DEBUG() << "Animal type " << _type;
}

/**
 * @brief Constructs a WrongAnimal with a specific type.
 * @param type The animal type string.
 */
WrongAnimal::WrongAnimal(const std::string& type) : _type(type)
{
	LOG_INFO() << "WrongAnimal type constructor called";
	LOG_DEBUG() << "Animal type " << _type;
}

/**
 * @brief Copy constructs a WrongAnimal.
 * @param other The WrongAnimal to copy from.
 */
WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	LOG_INFO() << "WrongAnimal copy constructor called";
	LOG_DEBUG() << "Animal type " << _type;
}

/**
 * @brief Assigns another WrongAnimal to this one.
 * @param other The WrongAnimal to assign from.
 * @return Reference to this WrongAnimal.
 */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	else
		LOG_WARNING() << "WrongAnimal self-assignment ignored";
	LOG_INFO() << "WrongAnimal assignment constructor called";
	LOG_DEBUG() << "Animal type " << _type;
	return (*this);
}


/** @brief Destroys the WrongAnimal instance. */
WrongAnimal::~WrongAnimal()
{
	LOG_INFO() << "WrongAnimal destructor called";
}

/**
 * @brief Returns the WrongAnimal type.
 * @return The type string.
 */
const std::string WrongAnimal::getType() const
{
	return (_type);
}

/** @brief Emits the WrongAnimal sound. */
void WrongAnimal::makeSound() const
{
	std::cout << "baaaaaaaa\n";
}
