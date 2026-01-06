/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_contacts.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:42:04 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/06 23:42:14 by diade-so         ###   ########.fr       */
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
 * @brief Displays the contacts, search contacts by index.
 *
 * Prompts user to enter index or RETURN to exit.
 * Validates input and prints the contact summary.
 * Throws std::runtime_error on EOF.
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
		if (!std::getline(std::cin, input))
			throw std::runtime_error("EOF");
		toUpperCase(input);
		if (input == "RETURN")
			return ;
		std::istringstream iss(input);

		int	index;
		if (!(iss >> index) || index < 1 || index > _totalContacts)
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
