/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:23:00 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:23:03 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "colors.hpp"
#include "utils.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

/**
 * @brief Construct a Weapon with a given type.
 *
 * @param type Weapon type string.
 * @throws std::invalid_argument if type is empty or whitespace only.
 */
Weapon::Weapon(const std::string& type) : _type(type)
{
	if (isBlank(type))
		throw std::invalid_argument("Weapon type cannot be empty");
	DBUG(std::cout << CYN "Weapon constructed: " << _type << RESET << '\n';)
}

/**
 * @brief Set the weapon type.
 *
 * @param type New weapon type.
 * @throws std::invalid_argument if type is empty or whitespace only.
 */
void Weapon::setType(const std::string& type)
{
	if (isBlank(type))
		throw std::invalid_argument("Weapon type cannot be empty");
	_type = type;
}

/**
 * @brief Get the weapon type.
 *
 * @return const std::string& Reference to the weapon type string.
 */
const std::string& Weapon::getType() const
{
	return (_type);
}
