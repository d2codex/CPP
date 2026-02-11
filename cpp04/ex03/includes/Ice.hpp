/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 02:19:44 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 02:19:45 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "Character.hpp"

/**
 * @class Ice
 * @brief Concrete AMateria representing ice magic.
 *
 * Implements cloning and using an ice spell on a character.
 */
class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);
	~Ice();

	AMateria*	clone() const;
	void		use(ICharacter& target);
};
