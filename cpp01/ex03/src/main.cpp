/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:22:41 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/25 14:45:55 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "colors.hpp"
#include <iostream>
#include <stdexcept>

/**
 * @brief Demo program for HumanA and HumanB behavior.
 *
 * Creates two scenarios:
 *   - HumanA owns a Weapon by reference and must be initialized with a valid Weapon.
 *   - HumanB is assigned a Weapon after construction.
 *
 * @note The Weapon class requires a valid, non-NULL string for its type.
 *       Passing a NULL C-string is invalid for std::string and results in
 *       undefined behavior unless explicitly handled.
 *
 * @note This version of main has been modified to catch exceptions thrown
 *       when invalid input (such as a NULL string) is provided.
 *       The original version supplied by the subject does not protect
 *       against this case and is therefore not exception-safe.
 *
 * Shows how updating the Weapon affects each human.
 */
int	main(void)
{
	try{

		{
			Weapon club = Weapon(NULL);

			HumanA bob("Bob", club);
			bob.attack();
			club.setType("some other type of club");
			bob.attack();
		}
		{
			Weapon club = Weapon("crude spiked club");

			HumanB jim("Jim");
			jim.setWeapon(club);
			jim.attack();
			club.setType("some other type of club");
			jim.attack();
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << RED "Error: " << e.what() << RESET << '\n';
	}
}
