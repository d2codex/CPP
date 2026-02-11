/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 02:20:33 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 02:20:34 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

/**
 * @brief Default constructor; initializes as an "ice" AMateria.
 */
Ice::Ice() : AMateria("ice")
{
	LOG_INFO()  << "Ice default constructor called";
	LOG_DEBUG() << "Materia type: " << _type << '\n'
			    << "Address: " << this;
}

/**
 * @brief Copy constructor; copies another Ice object.
 */
Ice::Ice(const Ice& other) : AMateria(other)
{
	LOG_INFO()  << "Ice copy constructor called";
	LOG_DEBUG() << "Materia type: " << _type << '\n'
			    << "Address: " << this;
}

/**
 * @brief Assignment operator; copies another Ice object.
 * @return Reference to this Ice.
 */
Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
		_type = other._type;
	}
	else
		LOG_WARNING() << "Ice self-assignment ignored";		
	LOG_INFO()  << "Ice assignment operator called";
	LOG_DEBUG() << "Materia Type: " << _type << '\n'
				<< "Address: " << this;
	return (*this);	
}

/**
 * @brief Destructor; cleans up the Ice object.
 */
Ice::~Ice()
{
	LOG_INFO() << "Ice destructor called";
}

/**
 * @brief Creates a new Ice object as a clone of this one.
 * @return Pointer to the cloned Ice.
 */
AMateria* Ice::clone() const
{
	Ice* clone = new Ice(*this);
	return (clone);
}

/**
 * @brief Uses the Ice on a target Character.
 * @param target Reference to target Character.
 */
void	Ice::use(ICharacter& target)
{
	std::cout << RED << "* shoots an ice bolt at "
			  << target.getName() << " *\n" << RESET;
}
