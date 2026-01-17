#include "HumanB.hpp"
#include "utils.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL)
{
	if (isBlank(_name))
		throw std::invalid_argument("Name cannot be empty");
	DBUG(std::cout << CYN "HumanB constructed: " << _name << RESET << '\n';);
}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void HumanB::attack() const
{
	std::cout << _name << " attacks with their ";
	if (_weapon)
		std::cout << _weapon->getType() << '\n';
	else
		std::cout << "hands\n";
}
