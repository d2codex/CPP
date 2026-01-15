#include "HumanA.hpp"
#include "utils.hpp"
#include <iostream>
#include <stdexcept>

HumanA::HumanA(const std::string& name, Weapon& weapon)
	: _name(name), _weapon(weapon)
{
	if (isBlank(name))
		throw std::invalid_argument("Name cannot be empty");
}

void HumanA::attack() const
{
	std::cout << _name << " attacks with their "
			  << _weapon.getType() << '\n';
}
