/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:37:43 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 10:49:46 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

/** @brief Constructs a Dog with type set to "dog". */
Dog::Dog() : Animal("dog")
{
	LOG_INFO() << "Dog default constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
}

/**
 * @brief Copy constructs a Dog.
 * @param other The Dog to copy from.
 */
Dog::Dog(const Dog& other) : Animal(other)
{
	LOG_INFO() << "Dog copy constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
}

/**
 * @brief Assigns another Dog to this one.
 * @param other The Dog to assign from.
 * @return Reference to this Dog.
 */
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	else
		LOG_WARNING() << "Dog self-assignment ignored";
	LOG_INFO() << "Dog assignment constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
	return (*this);
}

/** @brief Emits the dog sound. */
void Dog::makeSound() const
{
	std::cout << "woof woof bark bark\n";
	LOG_DEBUG() << "Animal type " << _type;
}

/** @brief Destroys the Dog instance. */
Dog::~Dog()
{
	LOG_INFO() << "Dog destructor called";
}
