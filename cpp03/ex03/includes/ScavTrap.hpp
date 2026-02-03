/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:45:06 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/04 00:45:08 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

/**
 * @class ScavTrap
 * @brief Derived class of ClapTrap with custom abilities.
 *
 * ScavTrap inherits from ClapTrap and can perform attacks with
 * custom messages and enter Gate Keeper Mode using guardGate().
 */
class ScavTrap : public virtual ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(ScavTrap& other);
	~ScavTrap();
	
	// actions
	void attack(const std::string& target);
	void guardGate();
};
