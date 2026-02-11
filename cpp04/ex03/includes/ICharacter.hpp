/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 02:19:32 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 02:19:33 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AMateria;

/**
 * @class ICharacter
 * @brief Interface for a character that can equip, unequip, and use Materia.
 *
 * Provides virtual functions for inventory management and interaction with
 * AMateria objects.
 */
class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual const std::string& getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
	virtual int getIndex(AMateria* m) const = 0;
};
