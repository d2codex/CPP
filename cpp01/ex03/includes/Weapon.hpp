/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:25:01 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:25:24 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#ifdef DEBUG
#define DBUG(x) x
#else
#define DBUG(x)
#endif

#include <string>

/**
 * @class Weapon
 * @brief Stores the type of weapon and allows updating it.
 *
 * The weapon type must be non-empty and not only whitespace.
 */
class Weapon
{
public:
	Weapon(const std::string& type);

	//setter
	void setType(const std::string& type);

	//getter
	const std::string& getType() const;

private:
	std::string _type;
};

#endif
