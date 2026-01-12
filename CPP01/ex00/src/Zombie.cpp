/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:58:47 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/12 13:59:05 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

/**
 * @brief Construct a new Zombie object with a name
 * @param name Name of the zombie
 */
Zombie::Zombie(std::string name) : _name(name)
{
}

/**
 * @brief Destroy the Zombie object and print self-destruct message
 */
Zombie::~Zombie()
{
	std::cout << "Self-Destructing...\n"
			  << _name << '\n';
}

/**
 * @brief Make the zombie announce itself
 */
void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
