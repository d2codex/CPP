#include "ClapTrap.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <sstream>

const unsigned int ClapTrap::_maxHP = 100;

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

/**
 * @brief Default constructor.
 * Initializes ClapTrap with default stats.
 */
ClapTrap::ClapTrap() : 
	_name("ClapTrap"),
	_hitPoints(_maxHP),
	_energyPoints(10),
	_attackDamage(0)
{
	LOG_INFO("ClapTrap default constructor called");
	// debug logging	
	std::ostringstream oss;
	oss << _name << '\n' 
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}

/**
 * @brief Construct a ClapTrap with a custom name.
 * @param name Name of the ClapTrap.
 */
ClapTrap::ClapTrap(const std::string& name) :
	_name(name),
	_hitPoints(_maxHP),
	_energyPoints(10),
	_attackDamage(0)
{
	LOG_INFO("ClapTrap name constructor called");
	// debug logging
	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}

/**
 * @brief Copy constructor.
 * @param other ClapTrap to copy from.
 */
ClapTrap::ClapTrap(const ClapTrap& other)
{
	LOG_INFO("ClapTrap copy constructor called");
	*this = other;
}

/**
 * @brief Copy assignment operator.
 * @param other ClapTrap to assign from.
 * @return Reference to this ClapTrap.
 */
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
		LOG_WARNING("ClapTrap self-assignment ignored");
	LOG_INFO("ClapTrap assignment operator called");
	// debug logging
	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
	return (*this);
}

/**
 * @brief Destructor.
 */
ClapTrap::~ClapTrap()
{
	LOG_INFO("ClapTrap destructor called");
}

/*****************************************************************************
 *                                  ACTIONS                                  *
 *****************************************************************************/

/**
 * @brief Attack a target, consuming HP and energy.
 * @param target Name of the target.
 *
 * Fails if ClapTrap is dead or out of energy.
 */
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
	_hitPoints -= 1;
	_energyPoints -= 1;
	std::cout << _name << MAG << " inflicts " << _attackDamage
			  << " damage on " << RESET << target << '\n';
	// debug logging	
	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("HP:    ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}

/**
 * @brief Apply damage to the ClapTrap.
 * @param amount Amount of damage taken.
 *
 * HP is reduced without underflow. Death sets HP and energy to zero.
 */
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
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
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
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}

/**
 * @brief Heal the ClapTrap, consuming energy.
 * @param amount Amount of HP to restore.
 *
 * Healing is capped at max HP. Energy is consumed even at full HP.
 */
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
	_hitPoints += amount;
	_energyPoints -= 1;
	if (maxHealable == 0)
		std::cout << _name << grn(" is at max HP (10)!\n");
	// debug logging
	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}
