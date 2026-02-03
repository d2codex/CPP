#pragma once

#include "ClapTrap.hpp"
#include <string>

/**
 * @class FragTrap
 * @brief Specialized ClapTrap with high-five ability.
 *
 * Inherits from ClapTrap and adds a positive interaction action.
 */
class FragTrap : public virtual ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();

	// actions
	void	highFiveGuys(void);
};
