/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:10:41 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 11:11:49 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

/** @brief Constructs a Brain with empty ideas. */
Brain::Brain()
{
	LOG_INFO() << "Brain default constructor called";
	LOG_DEBUG() << "Address: " << _ideas;
}

/**
 * @brief Copy constructs a Brain.
 * @param other The Brain to copy from.
 */Brain::Brain(const Brain& other)
{
	for (size_t i = 0; i < ARRAY_SIZE; i++)
		_ideas[i] = other._ideas[i];
	LOG_INFO() << "Brain copy constructor called";
	LOG_DEBUG() << "Address: " << _ideas;

}

/**
 * @brief Assigns another Brain to this one.
 * @param other The Brain to assign from.
 * @return Reference to this Brain.
 */
Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < ARRAY_SIZE; i++)
			_ideas[i] = other._ideas[i];
	}
	else
		LOG_WARNING() << "Brain self-assignment ignored";
	
	LOG_INFO() << "Brain assignment operator called";
	LOG_DEBUG() << "Address: " << _ideas;
	return (*this);
}

/** @brief Destroys the Brain instance. */
Brain::~Brain()
{
	LOG_INFO() << "Brain destructor called";
}

/**
 * @brief Returns the idea at a given index.
 * @param index The idea index.
 * @return The idea string.
 */
std::string Brain::getIdeaAtIndex(size_t index) const
{
	return (_ideas[index]);
}

/**
 * @brief Sets the idea at a given index.
 * @param idea The idea string to set.
 * @param index The index to set the idea at.
 */
void Brain::setIdeaAtIndex(const std::string& idea, size_t index)
{
	_ideas[index] = idea;
}
