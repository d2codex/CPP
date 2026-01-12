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
#include <string>

/**
 * @brief Create a heap-allocated zombie and return pointer
 * @param name Name of the zombie
 * @return Zombie* Pointer to the created zombie
 */
Zombie* newZombie(std::string name)
{
	Zombie* zombie = new Zombie(name);
	return (zombie);
}
