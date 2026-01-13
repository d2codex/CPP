#include "Zombie.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cerr << RED "Error. A horde must contain at least 1 zombie\n" RESET;
		return (NULL);
	}
	if (N > MAX_HORDE_SIZE)
	{
		std::cerr << RED "Error. Horde size exceeds max limit (1000000)\n" RESET;
		return (NULL);
	}

	Zombie *horde = NULL;
	try
	{
		horde = new Zombie[N];
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << RED "Error: memory allocation failed for " << N
				  << " zombies (" << e.what() << ")\n" RESET;
		return (NULL);
	}

	for(int i = 0; i < N; i++)
		horde[i].setZombieName(name);

	return (horde);
}
