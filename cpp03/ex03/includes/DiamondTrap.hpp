/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:44:49 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/04 00:44:53 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

/**
 * @class DiamondTrap
 * @brief Hybrid class combining ScavTrap and FragTrap behavior.
 *
 * DiamondTrap inherits attack behavior from ScavTrap and
 * hit points and attack damage from FragTrap.
 * It maintains its own name, distinct from ClapTrap.
 */
class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();

	//actions
	void attack(const std::string& target);
	void whoAmI();

private:
	std::string	_name;
};
