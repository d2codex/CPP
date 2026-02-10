#pragma once

#include "AMateria.hpp"
#include "Character.hpp"

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
