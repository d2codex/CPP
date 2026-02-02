#include "ClapTrap.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <sstream>

const unsigned int ClapTrap::_maxHP = 10;

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

ClapTrap::ClapTrap() : 
	_name("Default"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	LOG_INFO("Default Constructor called");
	
	std::ostringstream oss;
	oss << _name << '\n' 
		<< yel("Hit Points:    ") << _hitPoints << '\n'
		<< yel("Energy Points: ") << _energyPoints << '\n'
		<< yel("Attack Damage: ") << _attackDamage;

	LOG_DEBUG(oss.str());
}

ClapTrap::ClapTrap(const std::string& name) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	LOG_INFO("Constructor called");

	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("Hit Points:    ") << _hitPoints << '\n'
		<< yel("Energy Points: ") << _energyPoints << '\n'
		<< yel("Attack Damage: ") << _attackDamage;

	LOG_DEBUG(oss.str());
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	LOG_INFO("Copy constructor called");

	*this = other;

	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("Hit Points:    ") << _hitPoints << '\n'
		<< yel("Energy Points: ") << _energyPoints << '\n'
		<< yel("Attack Damage: ") << _attackDamage;

	LOG_DEBUG(oss.str());
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	else
		LOG_WARNING("Self-Assignment ignored");
	return (*this);
}

ClapTrap::~ClapTrap()
{
	LOG_INFO("Destructor Called");
}

/*****************************************************************************
 *                                  ACTIONS								     *
 *****************************************************************************/

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << RED << _name << " has died and cannot attack!\n"
				  << RESET;
		return ;
	}

	if (_energyPoints == 0)
	{
		std::cout << _name
				  << red(" has no energy left to attack!\n");
		return ;
	}
	
	// consume 1 hit point and 1 energy points
	_hitPoints -= 1;
	_energyPoints -= 1;

	// attack output
	std::cout << _name << MAG << " inflicts " << _attackDamage
			  << " damage on " << RESET << target << '\n';

	// debug logging	
	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("Hit Points:    ") << _hitPoints << '\n'
		<< yel("Energy Points: ") << _energyPoints << '\n'
		<< yel("Attack Damage: ") << _attackDamage;

	LOG_DEBUG(oss.str());
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << _name << red(" cannot take anymore damage\n");
		return ;
	}
	std::cout << _name << MAG << " takes " << amount << " damage\n" << RESET;
	if (amount >= _maxHP)
	{
		_hitPoints = 0;
		_energyPoints = 0;
		std::cout << _name << red(" has died.\n");

		// debug logging
		std::ostringstream oss;
		oss << _name << '\n'
		<< yel("Hit Points:    ") << _hitPoints << '\n'
		<< yel("Energy Points: ") << _energyPoints << '\n'
		<< yel("Attack Damage: ") << _attackDamage;
		LOG_DEBUG(oss.str());

		return ;
	}

	unsigned int maxDamageable = _hitPoints;
	if (amount > maxDamageable)
		amount = maxDamageable;
	
	_hitPoints -= amount;

	// debug logging	
	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("Hit Points:    ") << _hitPoints << '\n'
		<< yel("Energy Points: ") << _energyPoints << '\n'
		<< yel("Attack Damage: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << _name << red(" has died and cannot heal!\n");
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << _name << red(" has no energy left to heal!\n");
		return ;
	}

	std::cout << _name << GRN << " cast a heal for " << amount
			  << " HP!\n" << RESET;

	unsigned int maxHealable = _maxHP - _hitPoints;
	if (amount > maxHealable)
		amount = maxHealable;

	// Apply healing and consume energy
	_hitPoints += amount;
	_energyPoints -= 1;

	// healing output
	if (maxHealable == 0)
		std::cout << _name << grn(" is at max HP (10)!\n"); //still loses energy point

	// debugging output
	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("Hit Points:    ") << _hitPoints << '\n'
		<< yel("Energy Points: ") << _energyPoints << '\n'
		<< yel("Attack Damage: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}
