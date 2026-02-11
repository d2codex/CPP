#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

/**
 * @class Character
 * @brief Concrete implementation of ICharacter representing a player.
 *
 * Manages a fixed-size inventory of Materia and allows equipping, unequipping,
 * and using them on targets.
 */
class Character : public ICharacter
{
public:
	enum { MAX_SLOTS = 4 };

	Character(const std::string& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();

	const	std::string& getName() const;
	int		getIndex(AMateria* m) const;
	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);

private:
	std::string	_name;
	AMateria*	_inventory[MAX_SLOTS];
};
