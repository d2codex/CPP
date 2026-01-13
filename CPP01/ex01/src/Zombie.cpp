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
