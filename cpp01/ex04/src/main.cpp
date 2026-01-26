/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:41:09 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:41:11 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include "colors.hpp"
#include <fstream>
#include <iostream>
#include <string>

/**
 * @brief Entry point for the replace utility.
 *
 * Validates command-line arguments, then performs a string replace on
 * the given file. Returns 0 on success, 1 on failure.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return int 0 on success, 1 on error.
 */
int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << CYN
			"usage: ./bin/replace <filename> <search_str> <replace_str>\n" RESET;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << RED "Error: Search string cannot be empty\n" RESET;
		return (1);
	}
	if (replaceFile(filename, s1, s2))
		return (1);

	return (0);
}
