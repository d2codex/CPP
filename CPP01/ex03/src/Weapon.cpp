#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string weaponName) : _type(weaponName)
{
}

void Weapon::setType(const std::string& name)
{
	_type = name;
}

const std::string& Weapon::getType() const
{
	return (_type);
}

