/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 02:20:12 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 02:20:17 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Logger.hpp"
#include "colors.hpp"

/**
 * @brief Constructs an AMateria with the given type.
 */
AMateria::AMateria(const std::string& type) : _type(type)
{
	LOG_INFO() << "AMateria constructor called";
	LOG_DEBUG() << "Type: " << _type;
}

/**
 * @brief Copy constructor for AMateria.
 */
AMateria::AMateria(const AMateria& other) : _type(other._type)
{
	LOG_INFO() << "AMateria copy constructor called";
	LOG_DEBUG() << "Type: " << _type;
}

/**
 * @brief Assignment operator for AMateria.
 * @return Reference to this AMateria.
 */
AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		_type = other._type;
	else
		LOG_WARNING() << "AMateria self-assignment ignored";
	LOG_INFO() << "AMateria assignment operator called";
	LOG_DEBUG() << "Type: " << _type;
	return (*this);	
}

/**
 * @brief Destructor for AMateria.
 */
AMateria::~AMateria()
{
	LOG_INFO() << "AMateria destructor called";
}

/**
 * @brief Returns the type of the AMateria.
 * @return Reference to type string.
 */
const std::string& AMateria::getType() const
{
	return (_type);
}

/**
 * @brief Base use function; does nothing.
 * @param target Reference to target character.
 */
void AMateria::use(ICharacter& target)
{
    // Base AMateria does nothing
    (void)target; // silence unused parameter warning
}
