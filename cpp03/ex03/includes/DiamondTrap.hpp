#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

/**
 * @class DiamondTrap
 * @brief Hybrid class combining ScavTrap and FragTrap behavior.
 *
 * DiamondTrap inherits attack behavior from ScavTrap and
 * hit points and attack damage from FragTrap.
 * It maintains its own name, distinct from ClapTrap.
 */
class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();

	//actions
	void attack(const std::string& target);
	void whoAmI();

private:
	std::string	_name;
};
