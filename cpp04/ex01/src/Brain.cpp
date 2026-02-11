/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:01:41 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 11:02:16 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

/** @brief Constructs a Brain with empty ideas. */
Brain::Brain()
{
	// strings are automatically initialized to empty
	LOG_INFO() << "Brain default constructor called";
	LOG_DEBUG() << "Address: " << _ideas;
}

/**
 * @brief Copy constructs a Brain.
 * @param other The Brain to copy from.
 */
Brain::Brain(const Brain& other)
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

Brain::~Brain()
{
	LOG_INFO() << "Brain destructor called";
}

std::string Brain::getIdeaAtIndex(size_t index) const
{
	return (_ideas[index]);
}

void Brain::setIdeaAtIndex(const std::string& idea, size_t index)
{
	_ideas[index] = idea;
}
