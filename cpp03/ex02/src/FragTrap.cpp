#include "FragTrap.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <sstream>
#include <string>

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

FragTrap::FragTrap() : ClapTrap()
{
	_name = "FragTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	LOG_INFO("FragTrap default constructor called");
	// debug logging
	std::ostringstream oss;
	oss << _name << '\n' 
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	LOG_INFO("FragTrap string constructor called");
	// debug logging
	std::ostringstream oss;
	oss << _name << '\n' 
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	LOG_INFO("FragTrap copy constructor called");
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	else
		LOG_WARNING("FragTrap assignment ignored");

	LOG_INFO("FragTrap assignment operator called");
	// debug logging
	std::ostringstream oss;
	oss << _name << '\n' 
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
	return (*this);
}

FragTrap::~FragTrap()
{
	LOG_INFO("FragTrap destructor called");
}

/*****************************************************************************
 *                                  ACTIONS                                  *
 *****************************************************************************/

void FragTrap::highFiveGuys()
{
	std::cout << _name << mag(" Can I get a high-five guys!?\n");
}
