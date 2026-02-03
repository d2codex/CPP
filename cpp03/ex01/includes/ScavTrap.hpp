#pragma once

#include "ClapTrap.hpp"

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
