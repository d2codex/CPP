/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:01:34 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/25 01:11:27 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>
#include <sstream>

int	promptSize(void)
{
	std::string input;
	int	N;

	while (true)
	{
		std::cout << YEL "Enter horde size > " RESET;
		if(!std::getline(std::cin, input))
			throw std::runtime_error("Input stream closed");

		std::istringstream iss(input);
		if (!(iss >> N) || !iss.eof())
		{
			std::cerr << RED "Invalid input\n" RESET;
			continue ;
		}
		if (N <= 0)
		{
			std::cerr << RED "Error. A horde must contain at least 1 zombie\n" RESET;
			continue ;
		}
		if (N > MAX_HORDE_SIZE)
		{
			std::cerr << RED "Error. Horde size exceeds max limit (1000000)\n" RESET;
			continue ;
		}
		return (N);
	}
}

std::string	trim(const std::string& str)
{
	size_t start = 0;
	size_t end = str.length();

	while (start < end && std::isspace(static_cast<unsigned char>(str[start])))
		start++;
	while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
		end--;
	return (str.substr(start, end - start));
}

std::string promptName(void)
{
	std::string name;

	while (true)
	{
		std::cout << YEL "Enter zombie name > " RESET;
		if (!std::getline(std::cin, name))
			throw std::runtime_error("Input stream closed");
		if (name.empty())
		{
			std::cerr << RED "Name cannot be empty\n" RESET;
			continue ;
		}
		name = trim(name);
		return (name);
	}
}

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
