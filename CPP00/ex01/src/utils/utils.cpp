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
 * @brief Convert all letters in a string to uppercase.
 *
 * Modifies the string in-place.
 *
 * @param str The string to transform.
 */
void	toUpperCase(std::string& str)
{
	for (std::string::size_type i = 0; i < str.size(); ++i)
		str[i] = std::toupper(static_cast<unsigned char>(str[i]));
}

/**
 * @brief Trim leading/trailing spaces from a string.
 *
 * @param str The string to trim.
 * @return A trimmed copy of the string.
 */
std::string	trim(const std::string& str)
{
	size_t start = 0;
	size_t end = str.length();

	while (start < end && std::isspace(static_cast<unsigned char>(str[start])))
		start++;
	while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
		end--;
	return (str.substr(start, end - start));
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

/**
 * @brief Safely reads a line of input from std::cin into a string.
 *
 * Reads a line using std::getline() and checks for end-of-file or input
 * failure. Throws a std::runtime_error if the input stream is closed (EOF)
 * or in a failure state.
 *
 * @param out Reference to the string where the input will be stored.
 * @return true If the input was successfully read.
 * @throws std::runtime_error If the input stream is closed (EOF) or fails.
 */
bool	safeGetline(std::string& out)
{
	if (!std::getline(std::cin, out))
	{
		if (std::cin.eof())
			throw std::runtime_error("EOF");
		else {
			throw std::runtime_error("Input failure");
		}
	}
	return (true);
}
