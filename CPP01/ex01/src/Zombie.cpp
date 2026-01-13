#include "Zombie.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>

#ifdef DEBUG
int Zombie::s_constructed = 0;
int Zombie::s_destroyed = 0;
#endif

Zombie::Zombie() : _name()
{
	#ifdef DEBUG
	++s_constructed;

	if (s_constructed <= DISPLAY_LIMIT)
	{
		std::cout << "Constructing Zombie #" << s_constructed << '\n';
	}
	else if (s_constructed == DISPLAY_LIMIT + 1)
	{
			std::cout << "continuing construction...\n";
	}
	#endif
}

Zombie::~Zombie()
{
	#ifdef DEBUG
    ++s_destroyed;

    if (s_destroyed <= DISPLAY_LIMIT)
	{
		std::cout << YEL "Self-destructing..." RESET << '\n'
			      << "Zombie name: " << _name << '\n';
	}
    else if (s_destroyed == DISPLAY_LIMIT + 1)
		std::cout << "continuing destruction...\n";
	 // Print summary when last zombie is destroyed
    if (s_destroyed == s_constructed)
    {
        std::cout << YEL "\n[Debug] Total: " << s_constructed 
                  << " zombies created and destroyed\n\n" RESET;
    }
	#endif
}

#ifdef DEBUG
void Zombie::resetCounters()
{
    s_constructed = 0;
    s_destroyed   = 0;
}
#endif

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setZombieName(const std::string& name)
{
	_name = name;
}

