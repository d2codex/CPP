#include "DiamondTrap.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <sstream>

/**
 * @brief Default constructor.
 *
 * Initializes a DiamondTrap with default name and stats.
 * ClapTrap name is reassigned to "<name>_clap_name" locally,
 * preserving correct behavior for standalone ScavTrap and FragTrap.
 * Stats are inherited from FragTrap and ScavTrap.
 */
DiamondTrap::DiamondTrap() : 
	ClapTrap("DiamondTrap_clap_name"), ScavTrap(), FragTrap()
{
	_name = "DiamondTrap";
	ClapTrap::_name = "DiamondTrap_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	LOG_INFO("DiamondTrap default constructor called");
	// debug logging
	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}

/**
 * @brief Name constructor.
 *
 * Initializes a DiamondTrap with a custom name.
 * ClapTrap name is reassigned to "<name>_clap_name" locally,
 * preserving correct behavior for standalone ScavTrap and FragTrap.
 *
 * @param name Name of the DiamondTrap.
 */
DiamondTrap::DiamondTrap(const std::string& name) :
	ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	LOG_INFO("DiamondTrap name constructor called");
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
 * Creates a copy of another DiamondTrap instance.
 * @param other DiamondTrap to copy.
 */
DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	LOG_INFO("DiamondTrap copy constructor called");
}

/**
 * @brief Copy assignment operator.
 * Assigns the state of another DiamondTrap to this one.
 * @param other DiamondTrap to assign from.
 * @return Reference to this instance.
 */
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	else
		LOG_WARNING("DiamondTrap self-assignment ignored");
	LOG_INFO("DiamondTrap assignment constructor called");
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
 * Logs the destruction of the DiamondTrap instance.
 */
DiamondTrap::~DiamondTrap()
{
	LOG_INFO("Diamond destructor called");
}

/*****************************************************************************
 *                                  ACTIONS                                  *
 *****************************************************************************/

/**
 * @brief Attacks a target.
 *
 * Uses ScavTrap's attack behavior while displaying
 * the DiamondTrap name instead of the ClapTrap name.
 *
 * @param target Name of the target.
 */
void DiamondTrap::attack(const std::string& target)
{
	// Temporarily set ClapTrap::_name to DiamondTrap::_name
    std::string tmp = ClapTrap::_name;
    ClapTrap::_name = this->_name;

    // Call ScavTrap's attack (which uses ClapTrap::_name)
    ScavTrap::attack(target);

    // Restore the original ClapTrap name
    ClapTrap::_name = tmp;
}

/**
 * @brief Displays both identities.
 * Prints the DiamondTrap name and the internal
 * ClapTrap name used for inheritance.
 */
void DiamondTrap::whoAmI()
{
    std::cout << yel("DiamondTrap name: ") << _name << '\n';
    std::cout << yel("ClapTrap name: ") << ClapTrap::_name << '\n';
}
