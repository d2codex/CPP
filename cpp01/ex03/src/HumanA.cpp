/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:23:17 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:23:19 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include "colors.hpp"
#include "utils.hpp"
#include <iostream>
#include <stdexcept>

/**
 * @brief Construct a HumanA with a name and a weapon reference.
 *
 * @param name The human's name. Must not be empty or whitespace.
 * @param weapon Reference to the weapon the human will use.
 *
 * @throws std::invalid_argument If name is empty or whitespace only.
 */
HumanA::HumanA(const std::string& name, Weapon& weapon)
	: _name(name), _weapon(weapon)
{
	if (isBlank(name))
		throw std::invalid_argument("Name cannot be empty");
	DBUG(std::cout << CYN "HumanA Constructed: " << _name << RESET << '\n';)
}

/**
 * @brief Make the human attack with their weapon.
 *
 * Prints the attack message using the human name and weapon type.
 */
void HumanA::attack() const
{
	std::cout << _name << " attacks with their "
			  << _weapon.getType() << '\n';
}
