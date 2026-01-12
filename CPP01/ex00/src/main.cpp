#include "Zombie.hpp"
#include "colors.hpp"
#include <iostream>

int	main(void)
{
	Zombie* ptr = newZombie("Foo");
	ptr->announce();
	randomChump("Chump");

	DBUG(std::cout << YEL "Heap allocated: " RESET << ptr << '\n';)
	if (ptr)
	{
		DBUG(std::cout << YEL "deleting heap allocated: " RESET << ptr << '\n';)
		delete(ptr);
	}
}
