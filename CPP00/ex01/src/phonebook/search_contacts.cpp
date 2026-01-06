#include "phonebook.hpp"
#include "contact.hpp"
#include "utils.hpp"
#include <iostream>
#include <sstream>

static const size_t TABLE_COL_WIDTH = 10;

static std::string truncate(const std::string& str, size_t width)
{
	if(str.length() > width)
		return (str.substr(0, width - 1) + ".");
	return (str);
}

static std::string alignRight(const std::string& str, size_t width)
{
	if (str.length() >= width)
		return (str);
	return (std::string(width - str.length(), ' ') + str);
}

static std::string formatField(const std::string& str)
{
	return (alignRight(truncate(str, TABLE_COL_WIDTH), TABLE_COL_WIDTH));
}

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
