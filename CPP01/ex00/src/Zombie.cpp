#include "Zombie.hpp"
#include <string>
#include <iostream>

/**
 * @brief Construct a new Zombie object with a name
 * @param name Name of the zombie
 */
Zombie::Zombie(std::string name) : _name(name)
{
}

/**
 * @brief Destroy the Zombie object and print self-destruct message
 */
Zombie::~Zombie()
{
	std::cout << "Self-Destructing...\n"
			  << _name << '\n';
}

/**
 * @brief Make the zombie announce itself
 */
void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
