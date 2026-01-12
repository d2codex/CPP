#include "Zombie.hpp"
#include <string>

/**
 * @brief Create a heap-allocated zombie and return pointer
 * @param name Name of the zombie
 * @return Zombie* Pointer to the created zombie
 */
Zombie* newZombie(std::string name)
{
	Zombie* zombie = new Zombie(name);
	return (zombie);
}
