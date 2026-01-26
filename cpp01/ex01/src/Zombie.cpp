/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:01:47 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/25 01:03:55 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>

#ifdef DEBUG
int Zombie::s_constructed = 0;
int Zombie::s_destroyed = 0;
#endif

/**
 * @brief Default Zombie constructor.
 *
 * Initializes a Zombie with an empty name. In DEBUG mode, increments
 * the construction counter and prints limited construction output.
 */
Zombie::Zombie() : _name()
{
	#ifdef DEBUG
	++s_constructed;

	if (s_constructed <= DISPLAY_LIMIT)
	{
		std::cout << YEL "Constructing Zombie #" << s_constructed
				  << RESET << '\n';
	}
	else if (s_constructed == DISPLAY_LIMIT + 1)
	{
			std::cout << "continuing construction...\n";
	}
	#endif
}

/**
 * @brief Zombie destructor.
 *
 * In DEBUG mode, increments the destruction counter, prints limited
 * destruction output, and prints a summary once all Zombies are destroyed.
 */
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
/**
 * @brief Reset DEBUG construction and destruction counters.
 *
 * Intended for use between test cases.
 */
void Zombie::resetCounters()
{
    s_constructed = 0;
    s_destroyed   = 0;
}
#endif

/**
 * @brief Announce the Zombie.
 *
 * Prints the Zombie's name followed by its signature message.
 */
void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

/**
 * @brief Set the Zombie's name.
 *
 * @param name Name assigned to the Zombie.
 */
void	Zombie::setZombieName(const std::string& name)
{
	_name = name;
}

std::string Zombie::getName(void) const
{
	return (_name);
}
