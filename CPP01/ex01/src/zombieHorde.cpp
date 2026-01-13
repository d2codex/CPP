/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:01:34 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/13 18:01:36 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>

/**
 * @brief Create a horde of Zombies.
 *
 * Allocates an array of N Zombies on the heap and assigns each Zombie
 * the given name. The function validates the requested size and
 * handles memory allocation failures.
 *
 * @param N Number of Zombies to create.
 * @param name Name assigned to each Zombie.
 *
 * @return Pointer to the allocated Zombie array, or NULL if:
 *         - N <= 0
 *         - N exceeds MAX_HORDE_SIZE
 *         - memory allocation fails
 */
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
