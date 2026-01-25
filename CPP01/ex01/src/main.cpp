/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:01:41 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/25 00:58:54 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>
#include <sstream>

int	main(void)
{
	try
	{
		int	N = promptSize();
		std::string name = promptName();

		Zombie* horde = zombieHorde(N, name);
		
		if (horde)
		{
			for(int	i = 0; i < N; i++)
			{
				std::cout << "[" << i + 1 << "] ";
				horde->announce();
			}
		}
		delete[] horde;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED "Error: " << e.what() << RESET << '\n';
		return (1);
	}
}
