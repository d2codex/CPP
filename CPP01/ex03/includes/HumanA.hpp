/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:24:10 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:24:30 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

/**
 * @class HumanA
 * @brief A human that always has a weapon reference.
 *
 * HumanA stores a reference to a Weapon and can attack using it.
 */
class HumanA
{
public:
	HumanA(const std::string& name, Weapon& weapon);

	void	attack() const;

private:
	std::string	_name;
	Weapon&		_weapon;
};

#endif
