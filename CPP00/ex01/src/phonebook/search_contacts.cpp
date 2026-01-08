/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_contacts.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:42:04 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/07 01:47:22 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"
#include "utils.hpp"
#include <iostream>
#include <sstream>

static const size_t TABLE_COL_WIDTH = 10;

/**
 * @brief Truncate a string to the given width, adding '.' if needed.
 *
 * @param str The string to truncate.
 * @param width Max width for the string.
 * @return Truncated string.
 */
static std::string truncate(const std::string& str, size_t width)
{
	if(str.length() > width)
		return (str.substr(0, width - 1) + ".");
	return (str);
}

/**
 * @brief Align a string to the right within a given width.
 *
 * @param str The string to align.
 * @param width Total width to align to.
 * @return Right-aligned string.
 */
static std::string alignRight(const std::string& str, size_t width)
{
	if (str.length() >= width)
		return (str);
	return (std::string(width - str.length(), ' ') + str);
}

/**
 * @brief Format a string for table display.
 *
 * Combines truncation and right alignment using TABLE_COL_WIDTH.
 *
 * @param str The string to format.
 * @return Formatted string.
 */
static std::string formatField(const std::string& str)
{
	return (alignRight(truncate(str, TABLE_COL_WIDTH), TABLE_COL_WIDTH));
}

/**
 * @brief Print the phonebook as a table.
 *
 * Displays index, first name, last name, and nickname.
 * Each column is truncated and aligned for readability.
 */
void PhoneBook::printContactTable() const
{
	std::cout << YEL "-------------------------------------------\n" << RESET;
	std::cout << YEL "              THE YELLOW PAGE              \n" << RESET;
	std::cout << YEL "-------------------------------------------\n" << RESET;
	std::cout << formatField("Index")	   << YEL << "|" << RESET
			  << formatField("First Name") << YEL << "|" << RESET
			  << formatField("Last Name")  << YEL << "|" << RESET
			  << formatField("Nickname")   << "\n";
	std::cout << YEL "-------------------------------------------\n" << RESET;

	for (int i = 0; i < _totalContacts; i++)
	{
		std::cout << formatField(intToString(i + 1))		  << YEL << "|" << RESET
				  << formatField(_contacts[i].getFirstName()) << YEL << "|" << RESET
				  << formatField(_contacts[i].getLastName())  << YEL << "|" << RESET
				  << formatField(_contacts[i].getNickName())  << "\n";
		std::cout << YEL "-------------------------------------------\n" << RESET;
	}
}

/**
 * @brief Displays contacts and allows searching by index.
 *
 * Prompts for an index or "RETURN" to go back. Validates input and prints
 * the contact summary. Uses safeGetline(), which throws on EOF or failure.
 *
 * @throws std::runtime_error If input stream is closed or fails.
 */
void PhoneBook::searchContacts() const
{
	if (_totalContacts == 0)
	{
		std::cout << BLU << "Phonebook is empty.\n" << RESET;
		return ;
	}
	printContactTable();

	while (true)
	{
		std::string input;
		
		std::cout << "Enter the index number or RETURN to return to the main menu.\n"
				  << YEL << " > " RESET;
		safeGetline(input);
		toUpperCase(input);
		if (input == "RETURN")
			return ;
		std::istringstream inStream; // default constructor create empty stream
		inStream.str(input); // set content of stream to input string

		int	index;
		if (!(inStream >> index) || index < 1 || index > _totalContacts)
		{
			if (_totalContacts == 1)
				std::cout << RED << "Invalid input. Valid index: 1\n" << RESET;
			else
				std::cout << RED << "Invalid input. Valid index: 1 - "
						  << _totalContacts << "\n" << RESET;
			continue ;	
		}
		printContactSummary(_contacts[index - USER_INDEX_OFFSET]);
	}
}
