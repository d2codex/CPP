/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:42:40 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/06 23:42:42 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "colors.hpp"
#include <cctype>
#include <sstream>
#include <iostream>

/**
 * @brief Convert an integer to a string.
 *
 * Uses a string stream to format the integer as a std::string.
 *
 * @param n Integer to convert.
 * @return The integer as a std::string.
 */
std::string intToString(int n)
{
	std::ostringstream	outStream;

	outStream << n;
	return (outStream.str());
}

/**
 * @brief Convert all letters in a string to uppercase.
 *
 * Modifies the string in-place.
 *
 * @param str The string to transform.
 */
void	toUpperCase(std::string& str)
{
	for (std::string::size_type i = 0; i < str.size(); ++i)
		str[i] = std::toupper(str[i]);
}

/**
 * @brief Prompt the user for a YES/NO answer.
 *
 * Displays the message and returns true for YES, false for NO.
 * Throws a runtime_error if std::getline detects EOF.
 *
 * @param message The prompt message to display.
 * @return true if user types YES, false if NO.
 * @throws std::runtime_error on EOF.
 */
bool promptYesNo(const std::string& message)
{
	std::string	input;

	std::cout << message;
	while (true)
	{
		std::cout << YEL "> " << RESET;
		
		if (!std::getline(std::cin, input))
			throw std::runtime_error("EOF");
		toUpperCase(input);
		if (input == "YES")
			return (true);
		if (input == "NO")
			return (false);

		std::cout << RED << "Invalid input. Please type YES or NO.\n"
				  << RESET;
	}
}
