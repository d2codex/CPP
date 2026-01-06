#include "contact.hpp"
#include "phonebook.hpp"
#include "colors.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

static bool confirmExit()
{
	const std::string message =
		MAG "Exiting will delete all contacts in the phonebook.\n" RESET
		"Are you sure you want to exit?\n"
		"Type YES to exit and lose all information forever.\n"
		"Type NO to return to the prompt.\n";

	return (promptYesNo(message));
}

bool PhoneBook::isEmpty() const
{
	return (_totalContacts == 0);
}

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
