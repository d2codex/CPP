/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:00:29 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 11:02:27 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Logger.hpp"
#include "colors.hpp"

/** @brief Constructs an Animal with default type. */
Animal::Animal() : _type("Animal")
{
	LOG_INFO() << "Animal default constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
}

/**
 * @brief Constructs an Animal with a specific type.
 * @param type The animal type string.
 */
Animal::Animal(const std::string& type) : _type(type)
{
	LOG_INFO() << "Animal type constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
}

/**
 * @brief Copy constructs an Animal.
 * @param other The Animal to copy from.
 */
Animal::Animal(const Animal& other) : _type(other._type)
{
	LOG_INFO() << "Animal copy constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
}

/**
 * @brief Assigns another Animal to this one.
 * @param other The Animal to assign from.
 * @return Reference to this Animal.
 */
Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	else
		LOG_WARNING() << "Animal self-assignment ignored";
	LOG_INFO() << "Animal assignment operator called";
	LOG_DEBUG() << "Assignment type: " << _type; 
	return (*this);
}

/** @brief Destroys the Animal instance. */
Animal::~Animal()
{
	LOG_INFO() << "Animal destructor called";
}

/**
 * @brief Returns the animal type.
 * @return The type string.
 */
const std::string Animal::getType() const
{
	return (_type);
}

/** @brief Emits the animal sound. */
void Animal::makeSound() const
{
	std::cout << "!#$akd\n";
	LOG_DEBUG() << "Animal type: " << _type;
}
