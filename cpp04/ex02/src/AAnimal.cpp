/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:09:03 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 11:10:24 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Logger.hpp"
#include "colors.hpp"

/** @brief Constructs an AAnimal with default type. */
AAnimal::AAnimal() : _type("AAnimal")
{
	LOG_INFO() << "AAnimal default constructor called";
	LOG_DEBUG() << "AAnimal type: " << _type;
}

/**
 * @brief Constructs an AAnimal with a specific type.
 * @param type The animal type string.
 */
AAnimal::AAnimal(const std::string& type) : _type(type)
{
	LOG_INFO() << "AAnimal type constructor called";
	LOG_DEBUG() << "AAnimal type: " << _type;
}

/**
 * @brief Copy constructs an AAnimal.
 * @param other The AAnimal to copy from.
 */
AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
	LOG_INFO() << "AAnimal copy constructor called";
	LOG_DEBUG() << "AAnimal type: " << _type;
}

/**
 * @brief Assigns another AAnimal to this one.
 * @param other The AAnimal to assign from.
 * @return Reference to this AAnimal.
 */
AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	else
		LOG_WARNING() << "AAnimal self-assignment ignored";
	LOG_INFO() << "AAnimal assignment operator called";
	LOG_DEBUG() << "Assignment type: " << _type;
	return (*this);
}

/** @brief Destroys the AAnimal instance. */
AAnimal::~AAnimal()
{
	LOG_INFO() << "AAnimal destructor called";
}

/**
 * @brief Returns the animal type.
 * @return The type string.
 */
const std::string AAnimal::getType() const
{
	return (_type);
}

/** @brief Emits a generic animal sound (for demonstration). */
void AAnimal::makeSound() const
{
	std::cout << "!#$akd\n";
	LOG_DEBUG() << "AAnimal type: " << _type;
}
