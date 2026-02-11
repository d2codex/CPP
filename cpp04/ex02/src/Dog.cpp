/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:13:50 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 11:14:58 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

/** @brief Constructs a Dog with type "dog" and allocates a Brain. */
Dog::Dog() : AAnimal("dog"), _brain(new Brain())
{
	LOG_INFO() << "Dog default constructor called";
	LOG_DEBUG() << "AAnimal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
}

/**
 * @brief Copy constructs a Dog, including a deep copy of the Brain.
 * @param other The Dog to copy from.
 */
Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*other._brain))
{
	LOG_INFO() << "Dog copy constructor called";
	LOG_DEBUG() << "AAnimal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
}

/**
 * @brief Assigns another Dog to this one with deep Brain copy.
 * @param other The Dog to assign from.
 * @return Reference to this Dog.
 */
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		*_brain = *other._brain;
	}
	else
		LOG_WARNING() << "Dog self-assignment ignored";
	LOG_INFO() << "Dog assignment operator called";
	LOG_DEBUG() << "AAnimal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
	return (*this);
}

/**
 * @brief Returns the idea at a given index from the Dog's brain.
 * @param index The idea index.
 * @return The idea string.
 */
std::string Dog::getIdeaAtIndex(size_t index) const
{
	return (_brain->getIdeaAtIndex(index));
}

/**
 * @brief Sets the idea at a given index in the Dog's brain.
 * @param idea The idea string to set.
 * @param index The index to set the idea at.
 */
void Dog::setIdeaAtIndex(const std::string& idea, size_t index)
{
	_brain->setIdeaAtIndex(idea, index);
}

/** @brief Emits the dog sound. */
void Dog::makeSound() const
{
	std::cout << "woof woof bark bark\n";
	LOG_DEBUG() << "AAnimal type " << _type;
}

/** @brief Destroys the Dog and deallocates the Brain. */
Dog::~Dog()
{
	LOG_DEBUG() << "Deleting brain at " << _brain;
	delete _brain;
	LOG_INFO() << "Dog destructor called";
}
