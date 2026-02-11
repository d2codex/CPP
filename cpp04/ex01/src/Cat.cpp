/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:02:58 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 11:04:32 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

/** @brief Constructs a Cat with type "cat" and allocates a Brain. */
Cat::Cat() : Animal("cat"), _brain(new Brain())
{
	LOG_INFO() << "Cat default constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
}

/**
 * @brief Copy constructs a Cat, including a deep copy of the Brain.
 * @param other The Cat to copy from.
 */
Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
	LOG_INFO() << "Cat copy constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
}

/**
 * @brief Assigns another Cat to this one with deep Brain copy.
 * @param other The Cat to assign from.
 * @return Reference to this Cat.
 */
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	else
		LOG_WARNING() << "Cat self-assignment ignored";
	LOG_INFO() << "Cat assignment operator called";
	LOG_DEBUG() << "Animal type: " << _type;
	LOG_DEBUG() << "Address: " << _brain;
	return (*this);
}

/**
 * @brief Returns the idea at a given index from the Cat's brain.
 * @param index The idea index.
 * @return The idea string.
 */
std::string Cat::getIdeaAtIndex(size_t index) const
{
	return (_brain->getIdeaAtIndex(index));
}

/**
 * @brief Sets the idea at a given index in the Cat's brain.
 * @param idea The idea string to set.
 * @param index The index to set the idea at.
 */
void Cat::setIdeaAtIndex(const std::string& idea, size_t index)
{
	_brain->setIdeaAtIndex(idea, index);
}

/** @brief Emits the cat sound. */
void Cat::makeSound() const
{
	std::cout << "meow meow purr purr\n";
	LOG_DEBUG() << "Animal type: " << _type;
}

/** @brief Destroys the Cat and deallocates the Brain. */
Cat::~Cat()
{
	LOG_DEBUG() << "Deleting brain at " << _brain;
	delete _brain;
	LOG_INFO() << "Cat destructor called";
}
