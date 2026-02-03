#include "FragTrap.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <sstream>
#include <string>

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

/**
 * @brief Default constructor.
 * Initializes a FragTrap with default name and FragTrap stats.
 */
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

/**
 * @brief Name constructor.
 * Initializes a FragTrap with a custom name and FragTrap stats.
 * @param name Name of the FragTrap.
 */
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


/**
 * @brief Copy constructor.
 * Creates a FragTrap as a copy of another one.
 * @param other FragTrap to copy from.
 */
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	LOG_INFO("FragTrap copy constructor called");
}

F/**
 * @brief Copy assignment operator.
 * Assigns the state of another FragTrap to this one.
 * @param other FragTrap to assign from.
 * @return Reference to this FragTrap.
 */ragTrap& FragTrap::operator=(const FragTrap& other)
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


/**
 * @brief Destructor.
 * Destroys the FragTrap instance.
 */
FragTrap::~FragTrap()
{
	LOG_INFO("FragTrap destructor called");
}

/*****************************************************************************
 *                                  ACTIONS                                  *
 *****************************************************************************/

/**
 * @brief Requests a positive high-five from others.
 */
void FragTrap::highFiveGuys()
{
	std::cout << _name << mag(" Can I get a high-five guys!?\n");
}
