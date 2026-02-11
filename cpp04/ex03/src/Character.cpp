#include "Character.hpp"
#include "Logger.hpp"
#include "colors.hpp"

/**
 * @brief Constructs a Character with a given name and empty inventory.
 */
Character::Character(const std::string& name) :
	_name(name)
{
	for (size_t i = 0; i < MAX_SLOTS; i++)
	{
		_inventory[i] = NULL;
	}
	LOG_INFO() << "Character constructor called";
	LOG_DEBUG() << "Name:   " << _name << '\n'
				<< "Address:" << this;
}

/**
 * @brief Copy constructor; deep copies equipped Materia.
 */
Character::Character(const Character& other) : _name(other._name)
{
	for (size_t i = 0; i < MAX_SLOTS; i++)
		_inventory[i] = NULL;

    for (size_t i = 0; i < MAX_SLOTS; i++)
    {
        if (other._inventory[i] != NULL)
            _inventory[i] = other._inventory[i]->clone();
    }
	LOG_INFO() << "Character copy constructor called";
	LOG_DEBUG() << "Name:   " << _name << '\n'
				<< "Address:" << this;
}

/**
 * @brief Assignment operator; deep copies inventory from other Character.
 * @return Reference to this Character.
 */
Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for(size_t i = 0; i < MAX_SLOTS; i++)
		{
			// make sure theres nothing in this inventory first
			if (_inventory[i] != NULL)
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (other._inventory[i] != NULL)
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	else
		LOG_WARNING() << "Character self-assignment ignored";
	LOG_INFO() << "Character assignment operator called";
	LOG_DEBUG() << "Name:   " << _name << '\n'
				<< "Address:" << this;
	return (*this);
}

/**
 * @brief Destructor; deletes all equipped Materia.
 */
Character::~Character()
{
	for(size_t i = 0; i < MAX_SLOTS; i++)
	{
		if (_inventory[i] != NULL)
		{
			LOG_DEBUG() << "Deleting materia at " << _inventory[i];
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	LOG_INFO() << "Character destructor called";
}

/**
 * @brief Returns the name of the Character.
 * @return Reference to name string.
 */
const std::string& Character::getName() const
{
	return (_name);
}

/**
 * @brief Returns the inventory index of a given Materia.
 * @param m Pointer to Materia.
 * @return Index if found, -1 otherwise.
 */
int	Character::getIndex(AMateria* m) const
{
	for (size_t i = 0; i < MAX_SLOTS; i++)
	{
		if (_inventory[i] == m)
			return (i);
	}
	return (-1);
}

/**
 * @brief Equips a Materia in the first available slot.
 * @param m Pointer to Materia to equip.
 */
void	Character::equip(AMateria* m)
{
	if (!m)
	{
		LOG_WARNING() << mag("[equip] Materia not found");
		return ;
	}
	for (size_t i = 0; i < MAX_SLOTS; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			LOG_INFO() << BLU << "Materia equipped in slot " << i << RESET;
			return ;
		}
	}
	LOG_WARNING() << mag("[equip] Inventory full");
}

/**
 * @brief Unequips a Materia at a given inventory index.
 * @param idx Index to unequip.
 */
void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_SLOTS)
	{
		LOG_WARNING() << mag("[unequip] Invalid index. Cannot unequip");
		return ;
	}
	if (_inventory[idx] != NULL)
	{
		LOG_INFO() << BLU << "Unequipping materia from slot " << idx << RESET;
		_inventory[idx] = NULL;
	}
	else
		LOG_WARNING() << mag("[unequip] No materia to unequip");
}

/**
 * @brief Uses the Materia at a given inventory slot on a target.
 * @param idx Index of Materia to use.
 * @param target Reference to target Character.
 */
void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_SLOTS)
	{
		LOG_WARNING() << mag("[use] Invalid inventory slot!");
		return ;
	}
	if (_inventory[idx] != NULL)
		_inventory[idx]->use(target);
	else
		LOG_WARNING() << mag("[use] No materia equipped");
}
