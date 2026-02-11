#include "Character.hpp"
#include "Logger.hpp"
#include "colors.hpp"

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

const std::string& Character::getName() const
{
	return (_name);
}

int	Character::getIndex(AMateria* m) const
{
	for (size_t i = 0; i < MAX_SLOTS; i++)
	{
		if (_inventory[i] == m)
			return (i);
	}
	return (-1);
}

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
