#include "ScavTrap.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <sstream>

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "ScavTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	LOG_INFO("ScavTrap Default Constructor called");

	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	LOG_INFO("ScavTrap String Constructor called");

	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	LOG_INFO("ScavTrap Copy Constructor called");
}

ScavTrap& ScavTrap::operator=(ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	else
		LOG_WARNING("ScavTrap Self-Assignment Ignored");

	LOG_INFO("ScavTrap Assignment Operator called");
	// debug logging
	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
	return (*this);
}

ScavTrap::~ScavTrap()
{
	LOG_INFO("ScavTrap Deconstructor Called");
}

/*****************************************************************************
 *                                  ACTIONS                                  *
 *****************************************************************************/

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << _name
				  << red(" has been deactivated! Systems offline...\n");
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << RED << _name
				  << " is out of battery! Cannot perform actions.\n"
				  << RESET;
		return;
	}

	std::cout << _name << mag(" launches a glitter bomb at ")
			  << target << MAG << " dealing " << _attackDamage
			  << " damage!!\n" << RESET;

	_hitPoints -= 1;
	_energyPoints -=  1;
	// debug logging
	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}

void ScavTrap::guardGate()
{
	std::cout << mag("ScavTrap is now in Gate Keeper Mode\n");
}
