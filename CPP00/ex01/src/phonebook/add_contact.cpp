#include "contact.hpp"
#include "phonebook.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <iostream>

PhoneBook::PhoneBook() : _nextIndex(0), _totalContacts(0)
{
    // _contacts array will default-construct each Contact automatically
}

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

static bool	isAllDigits(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
	}
	return (true);
}

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

bool	PhoneBook::confirmSave() const
{
	const std::string message =
		CYN "Save this contact? Type YES to save, NO to cancel.\n" RESET;

	return (promptYesNo(message));
}

void	PhoneBook::printContactSummary(const Contact& contact) const
{
	std::cout << YEL << "Contact Information:\n" << RESET;
	std::cout << "First Name    : " << contact.getFirstName() << "\n"
			  << "Last Name     : " << contact.getLastName() << "\n"
			  << "Nickname      : " << contact.getNickName() << "\n"
			  << "Phone Number  : " << contact.getPhoneNumber() << "\n"
			  << "Darkest Secret: " << contact.getDarkestSecret() << "\n";
}

bool	PhoneBook::confirmReplacement(const Contact& oldContact) const
{
	std::cout << MAG << "The phonebook is full. Replace the oldest contact?\n"
			  << RESET;
	printContactSummary(oldContact);
	const std::string message = "Type YES to replace, NO to cancel.\n";

	return (promptYesNo(message));
}

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
