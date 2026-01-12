#include "Zombie.hpp"
#include <string>

/**
 * @brief Create a stack zombie, announce immediately
 * @param name Name of the zombie
 */
void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}
