#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter
{
public:
	enum { MAX_SLOTS = 4 };

	Character(const std::string& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();

	const	std::string& getName() const;
	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);

private:
	std::string	_name;
	AMateria*	_inventory[MAX_SLOTS];
};
