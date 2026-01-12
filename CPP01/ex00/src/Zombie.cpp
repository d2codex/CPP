#include "Zombie.hpp"
#include <string>
#include <iostream>

// constructor / destructor
Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << "Self-Destructing...\n"
			  << _name << '\n';
}

// member functions
void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
