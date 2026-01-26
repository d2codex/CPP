/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:00:39 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/19 11:01:24 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>

/**
 * @brief Program entry point for the Harl filter.
 *
 * Expects exactly one argument specifying the complaint level.
 * If the level is valid, prints messages from that level and above.
 *
 * @param argc Argument count (should be 2).
 * @param argv Argument vector (argv[1] is the level string).
 * @return 0 on success, 1 on invalid usage.
 */
int	main(int argc, char **argv)
{
	Harl harl;
	if (argc != 2)
	{
		std::cout << YEL "Usage: ./harlFilter <level>\n" RESET;
		return (1);
	}
	std::string level = argv[1];
	harl.complainLevel(level);
}
