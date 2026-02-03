/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:46:32 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/04 00:46:34 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>
#include <sstream>

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

/**
 * @brief Default constructor. Initializes a ScavTrap with default stats.
 */
ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "ScavTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	LOG_INFO("ScavTrap default constructor called");
	// debug logging
	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}

/**
 * @brief String constructor. Sets name and initializes ScavTrap stats.
 * @param name Name of the ScavTrap instance
 */
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	LOG_INFO("ScavTrap name constructor called");
	// debug logging
	std::ostringstream oss;
	oss << _name << '\n'
		<< yel("HP: ") << _hitPoints << '\n'
		<< yel("EP: ") << _energyPoints << '\n'
		<< yel("AD: ") << _attackDamage;
	LOG_DEBUG(oss.str());
}

/**
 * @brief Copy constructor. Creates a copy of another ScavTrap.
 * @param other ScavTrap instance to copy
 */
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	LOG_INFO("ScavTrap copy constructor called");
}

/**
 * @brief Assignment operator. Copies stats from another ScavTrap.
 * @param other ScavTrap instance to assign from
 * @return Reference to *this
 */
ScavTrap& ScavTrap::operator=(ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	else
		LOG_WARNING("ScavTrap self-assignment ignored");

	LOG_INFO("ScavTrap assignment operator called");
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
 * @brief Destructor. Logs destruction of the ScavTrap instance.
 */
ScavTrap::~ScavTrap()
{
	LOG_INFO("ScavTrap deconstructor called");
}

/*****************************************************************************
 *                                  ACTIONS                                  *
 *****************************************************************************/

/**
 * @brief Attack a target. Prints a custom message and consumes energy.
 * @param target Name of the target to attack
 */
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

/**
 * @brief Enter Guard Gate mode. Prints a message.
 */
void ScavTrap::guardGate()
{
	std::cout << mag("ScavTrap is now in Gate Keeper Mode\n");
}
