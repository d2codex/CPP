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
#include "colors.hpp"
#include <string>
#include <iostream>

/**
 * @brief Create a stack zombie and announce immediately.
 *
 * @param name Name of the zombie. Must be a valid string.
 *
 * @note Passing a null pointer (nullptr) causes std::string to throw
 *       before this function is entered. If invalid input is possible,
 *       wrap the call in a try/catch block.
 */
void randomChump(std::string name)
{
	if (name.empty())
		throw std::invalid_argument("Name cannot be empty.");
	Zombie zombie(name);
	zombie.announce();
}
