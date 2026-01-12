/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:58:40 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/12 13:59:14 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

/**
 * @brief Create a stack zombie, announce immediately
 * @param name Name of the zombie
 */
void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}
