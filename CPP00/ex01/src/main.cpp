/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:42:48 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/06 23:42:53 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"
#include "colors.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/**
 * @brief Ask the user to confirm program exit.
 *
 * Displays a warning message and returns true if the user confirms
 * the exit, false otherwise.
 */
static bool confirmExit()
{
	const std::string message =
		MAG "Exiting will delete all contacts in the phonebook.\n" RESET
		"Are you sure you want to exit?\n"
		"Type YES to exit and lose all information forever.\n"
		"Type NO to return to the prompt.\n";

	return (promptYesNo(message));
}

/**
 * @brief Check if the phonebook has no stored contacts.
 *
 * @return true if the phonebook is empty, false otherwise.
 */
bool PhoneBook::isEmpty() const
{
	return (_totalContacts == 0);
}

/**
 * @brief Entry point of the PhoneBook program.
 *
 * Displays the main menu, processes user commands, and handles
 * end-of-file conditions using exceptions.
 *
 * @return Exit status of the program.
 */
int	main(void)
{
	PhoneBook phonebook;
	std::string command;
	try
	{
		while (true)
		{
			std::cout << YEL << "    === Welcome to the PhoneBook ===\n" << RESET;
			std::cout << "Type ADD to add a contact to the phonebook\n";
			std::cout << "Type SEARCH to display the phonebook\n";
			std::cout << "Type EXIT to exit the program\n";
			std::cout << YEL << "> " << RESET;
			if (!std::getline(std::cin, command))
				throw std::runtime_error("EOF");
			toUpperCase(command);
			if (command == "ADD")
				phonebook.addContact();
			else if (command == "SEARCH")
				phonebook.searchContacts();
			else if (command == "EXIT")
			{
				if (phonebook.isEmpty())
					break ;
				if (confirmExit())
					break ;
			}
			else
				std::cout << RED << "Invalid command. Please try again.\n" << RESET;
			std::cout << "\n";
		}
	}
	catch (const std::runtime_error& e)
	{
		std::cout << "\n" << BLU << "Input stream closed.\n" << RESET;
	}
	std::cout << BLU << "Goodbye and have a nice day.\n" << RESET;
	return (0);
}
