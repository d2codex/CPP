/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:58:42 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/12 13:59:11 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "colors.hpp"
#include <iostream>

/**
 * @brief Test Zombie class and free functions
 *
 * - Creates a heap zombie using newZombie() and announces it
 * - Creates a stack zombie using randomChump()
 * - Demonstrates debug logging and proper heap deletion
 */
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
