/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:40:47 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/04 00:40:48 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <string>

/**
 * @class FragTrap
 * @brief Specialized ClapTrap with high-five ability.
 *
 * Inherits from ClapTrap and adds a positive interaction action.
 */
class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();

	// actions
	void	highFiveGuys(void);
};
