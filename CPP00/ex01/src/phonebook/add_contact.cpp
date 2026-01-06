/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:42:28 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/06 23:42:30 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <iostream>

/**
 * @brief Construct a new PhoneBook object.
 *
 * Initializes _nextIndex and _totalContacts to 0.
 * _contacts array is default-constructed automatically.
 */
PhoneBook::PhoneBook() : _nextIndex(0), _totalContacts(0)
{
    // _contacts array will default-construct each Contact automatically
}

/**
 * @brief Trim leading/trailing spaces or hyphens from a string.
 *
 * @param str The string to trim.
 * @return A trimmed copy of the string.
 */
static std::string	trim(const std::string& str)
{
	size_t start = 0;
	size_t end = str.length();

	while (start < end && (std::isspace(static_cast<unsigned char>(str[start]))
			|| str[start] == '-'))
		start++;
	while (end > start && (std::isspace(static_cast<unsigned char>(str[end - 1]))
			|| str[end] == '-'))
		end--;
	return (str.substr(start, end - start));
}

/**
 * @brief Check if a string is a valid name.
 *
 * Allows letters, spaces, and hyphens only.
 *
 * @param str The string to validate.
 * @return true if valid, false otherwise.
 */
static bool	isValidName(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (!std::isalpha(static_cast<unsigned char>(c)) &&
			c != ' ' &&
			c != '-')
			return (false);
	}
	return (true);
}

/**
 * @brief Prompt the user to enter a valid name.
 *
 * Uses std::getline and validates input with trim and isValidName.
 * Throws std::runtime_error on EOF.
 *
 * @param prompt The prompt message to display.
 * @return The validated name string.
 */
std::string	PhoneBook::promptName(const std::string& prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt << YEL " > " << RESET;
		if (!std::getline(std::cin, input))
			throw std::runtime_error("EOF");
		input = trim(input);
		if (input.empty())
		{
			std::cout << RED << "Field cannot be empty. Please try again.\n"
					  << RESET;
			continue ;
		}
		if (!isValidName(input))
		{
			std::cout << RED << "Only letters, spaces and hypens are allowed.\n"
					  << RESET;
			continue ;
		}
		return (input);
	}
}

/**
 * @brief Check if a string contains only digits.
 *
 * @param str The string to validate.
 * @return true if all chars are digits, false otherwise.
 */
static bool	isAllDigits(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
	}
	return (true);
}

/**
 * @brief Prompt the user for a 10-digit phone number.
 *
 * Trims whitespace and validates length/digits.
 * Throws std::runtime_error on EOF.
 *
 * @param prompt The prompt message.
 * @return The validated phone number string.
 */
std::string	PhoneBook::promptPhoneNumber(const std::string& prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt << " (10 digits)" << YEL " > " << RESET;
		if (!std::getline(std::cin, input))
			throw std::runtime_error("EOF");
		input = trim(input);
		if (input.length() == PHONE_LEN && isAllDigits(input))
			return (input);
		std::cout << RED << "Invalid phone number.  Must be eactly 10 digits.\n"
				  << RESET;
	}
}

/**
 * @brief Prompt the user for non-empty input.
 *
 * Throws std::runtime_error on EOF.
 *
 * @param prompt The prompt message.
 * @return The non-empty input string.
 */
std::string	PhoneBook::promptNonEmpty(const std::string& prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt << YEL " > " << RESET;
		if (!std::getline(std::cin, input))
			throw std::runtime_error("EOF");
		if (!input.empty())
			return (input);
		std::cout << RED << "Input cannot be empty.  Please try again.\n"
				  << RESET;
	}
}

/**
 * @brief Ask the user to confirm saving a contact.
 *
 * Uses promptYesNo to get YES/NO input.
 *
 * @return true if user confirms save.
 */
bool	PhoneBook::confirmSave() const
{
	const std::string message =
		CYN "Save this contact? Type YES to save, NO to cancel.\n" RESET;

	return (promptYesNo(message));
}

/**
 * @brief Print a contact's details to stdout.
 *
 * Shows first/last name, nickname, phone, and secret.
 *
 * @param contact The contact to display.
 */
void	PhoneBook::printContactSummary(const Contact& contact) const
{
	std::cout << YEL << "Contact Information:\n" << RESET;
	std::cout << "First Name    : " << contact.getFirstName() << "\n"
			  << "Last Name     : " << contact.getLastName() << "\n"
			  << "Nickname      : " << contact.getNickName() << "\n"
			  << "Phone Number  : " << contact.getPhoneNumber() << "\n"
			  << "Darkest Secret: " << contact.getDarkestSecret() << "\n";
}

/**
 * @brief Ask user to replace the oldest contact if full.
 *
 * Prints the old contact info and prompts YES/NO.
 *
 * @param oldContact The contact to potentially replace.
 * @return true if replacement confirmed.
 */
bool	PhoneBook::confirmReplacement(const Contact& oldContact) const
{
	std::cout << MAG << "The phonebook is full. Replace the oldest contact?\n"
			  << RESET;
	printContactSummary(oldContact);
	const std::string message = "Type YES to replace, NO to cancel.\n";

	return (promptYesNo(message));
}

/**
 * @brief Add a new contact to the phonebook.
 *
 * Prompts user for first/last/nick/phone/secret.
 * Validates input, confirms save, and handles circular storage.
 */
void	PhoneBook::addContact()
{
	std::string first = promptName("Enter first name");
	std::string last = promptName("Enter last name");
	std::string nick = promptName("Enter nickname");
	std::string phone = promptPhoneNumber("Enter phone number");
	std::string secret = promptNonEmpty("Enter darkest secret");

	Contact temp;
	temp.setContact(first, last, nick, phone, secret);
	printContactSummary(temp);
	if (!confirmSave())
		return ;
	if (_totalContacts == MAX_CONTACTS)
	{
		if (!confirmReplacement(_contacts[_nextIndex]))
			return ;
	}
	_contacts[_nextIndex].setContact(first, last, nick, phone, secret);
	_nextIndex = (_nextIndex + 1) % MAX_CONTACTS;
	if (_totalContacts < MAX_CONTACTS)
		_totalContacts++;
}
