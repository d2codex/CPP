/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 02:19:24 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 02:19:25 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "Character.hpp"
#include <string>

/**
 * @class Cure
 * @brief Concrete AMateria representing a healing spell.
 *
 * Can be cloned and used to heal a target character.
 */
class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	~Cure();

	AMateria*	clone() const;
	void		use(ICharacter& target);
};
