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
