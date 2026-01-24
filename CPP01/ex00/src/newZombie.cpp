/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:58:45 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/12 13:59:08 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>

/**
 * @brief Create a zombie on the heap and return it.
 *
 * @param name Name of the zombie. Must be a valid std::string.
 * @return Zombie* Pointer to the heap-allocated zombie.
 *
 * @note Passing an invalid C-string (nullptr) causes std::string to throw
 *       an exception before this function is entered. If invalid input is
 *       possible, wrap the call in a try/catch block to avoid a crash.
 */
Zombie* newZombie(std::string name)
{
	if (name.empty())
		throw std::invalid_argument ("Name cannot be empty.");
	
	Zombie* zombie = new Zombie(name);
	return (zombie);
}
