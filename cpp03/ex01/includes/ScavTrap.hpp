#pragma once

#include "ClapTrap.hpp"

/**
 * @class ScavTrap
 * @brief Derived class of ClapTrap with custom abilities.
 *
 * ScavTrap inherits from ClapTrap and can perform attacks with
 * custom messages and enter Gate Keeper Mode using guardGate().
 */
class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(ScavTrap& other);
	~ScavTrap();
	
	// actions
	void attack(const std::string& target);
	void guardGate();
};
