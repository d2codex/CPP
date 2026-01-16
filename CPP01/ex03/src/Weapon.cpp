#include "Weapon.hpp"
#include "utils.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

Weapon::Weapon(const std::string& type) : _type(type)
{
	if (isBlank(type))
		throw std::invalid_argument("Weapon type cannot be empty");
	DBUG(std::cout << "Weapon constructed: " << _type << '\n';)
}

void Weapon::setType(const std::string& type)
{
	if (isBlank(type))
		throw std::invalid_argument("Weapon type cannot be empty");
	_type = type;
}

const std::string& Weapon::getType() const
{
	return (_type);
}

