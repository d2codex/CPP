/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:26:11 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:26:33 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

/**
 * @class HumanB
 * @brief Represents a human who can be assigned a weapon later.
 *
 * The weapon is stored as a pointer and may be null until set.
 */
class HumanB
{
public:
	HumanB(const std::string& name);

	void	setWeapon(Weapon& weapon);
	void	attack() const;

private:
	std::string _name;
	Weapon*		_weapon;
};
