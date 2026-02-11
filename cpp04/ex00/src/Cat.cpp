/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:37:33 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 10:48:17 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

/** @brief Constructs a Cat with type set to "cat". */
Cat::Cat() : Animal("cat")
{
	LOG_INFO() << "Cat default constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
}

/**
 * @brief Copy constructs a Cat.
 * @param other The Cat to copy from.
 */
Cat::Cat(const Cat& other) : Animal(other)
{
	LOG_INFO() << "Cat copy constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
}

/**
 * @brief Assigns another Cat to this one.
 * @param other The Cat to assign from.
 * @return Reference to this Cat.
 */
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other); // update derived class
	}
	else
		LOG_WARNING() << "Cat self-assignment ignored";
	LOG_INFO() << "Cat assignment constructor called";
	LOG_DEBUG() << "Animal type: " << _type;
	return (*this);
}

/** @brief Emits the cat sound. */
void Cat::makeSound() const
{
	std::cout << "meow meow purr purr\n";
	LOG_DEBUG() << "Animal type: " << _type;
}

/** @brief Destroys the Cat instance. */
Cat::~Cat()
{
	LOG_INFO() << "Cat destructor called";
}
