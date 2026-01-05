#include "contact.hpp"
#include "phonebook.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

static bool confirmExit()
{
	std::string input;
		
	std::cout << CYN "Exiting will delete all contacts in the phonebook.\n"
			  << RESET;
	std::cout << "Are you sure you want to exit?\n";
	std::cout << "Type YES to exit and lose all information forever.\n";
	std::cout << "Type NO to return to the prompt.\n";

	while (true)
	{
		std::cout << YEL "> " << RESET;

		if (!std::getline(std::cin, input))
			return (true); // EOF -> exit safely
		if (input == "YES" || input == "yes")
			return (true);
		if (input == "NO" || input == "no")
			return (false);

		std::cout << "Invalid input.  Please type YES or NO.\n";
	}
}

int	main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		std::cout << YEL << "    === Welcome to the PhoneBook ===\n" << RESET;
		std::cout << "Type ADD to add a contact to the phonebook\n";
		std::cout << "Type SEARCH to display the phonebook\n";
		std::cout << "Type EXIT to exit the program\n";
		std::cout << YEL << "> " << RESET;
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD" || command == "add")
			phonebook.addContact();
	//	else if (command == "SEARCH" || command == "search")
	//		phonebook.searchContacts();
		else if (command == "EXIT" || command == "exit")
		{
			if (confirmExit())
				break ;
		}
		else
			std::cout << RED << "Invalid command. Please try again.\n" << RESET;
		std::cout << "\n";
	}
	std::cout << BLU << "Goodbye and have a nice day.\n" << RESET;
	return (0);
}
