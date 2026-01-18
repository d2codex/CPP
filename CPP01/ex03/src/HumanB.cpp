/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:23:08 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:23:10 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "utils.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>

/**
 * @brief Construct a HumanB with a name and no initial weapon.
 *
 * @param name The human's name. Must not be empty or whitespace.
 *
 * @throws std::invalid_argument If name is empty or whitespace only.
 */
HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL)
{
	if (isBlank(_name))
		throw std::invalid_argument("Name cannot be empty");
	DBUG(std::cout << CYN "HumanB constructed: " << _name << RESET << '\n';);
}

/**
 * @brief Assign a weapon to the human.
 *
 * @param weapon Reference to the weapon to be assigned.
 */
void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

/**
 * @brief Make the human attack using their weapon or hands.
 *
 * Prints the attack message. If no weapon is set, attacks with hands.
 */
void HumanB::attack() const
{
	std::cout << _name << " attacks with their ";
	if (_weapon)
		std::cout << _weapon->getType() << '\n';
	else
		std::cout << "hands\n";
}
