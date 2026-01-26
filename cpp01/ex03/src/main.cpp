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
 * @note The subject version of main does not include exception handling.
 *       If you want to test invalid input (e.g. NULL), you would need to
 *       add a try/catch block around the code.
 */
int	main(void)
{
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
