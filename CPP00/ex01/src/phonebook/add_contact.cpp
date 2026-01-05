#include "contact.hpp"
#include "phonebook.hpp"
#include <cstdlib>

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
	size_t i = 0;

	while (i < str.length())
	{
		char c = str[i];
		if (!std::isalpha(static_cast<unsigned char>(c)) &&
			c != ' ' &&
			c != '-')
			return (false);
		i++;
	}
	return (true);
}

std::string	PhoneBook::promptName(const std::string& prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt << YEL " > " << RESET;
		std::getline(std::cin, input);
		if (!std::cin)
			exit (0);
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
	size_t	i = 0;

	while (i < str.length())
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
		i++;
	}
	return (true);
}

//prompts user until they enter a valid 10-digit phone number
std::string	PhoneBook::promptPhoneNumber(const std::string& prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt << " (10 digits)" << YEL " > " << RESET;
		std::getline(std::cin, input);

		if (!std::cin)
			exit (0);
		input = trim(input);
		if (input.length() == 10 && isAllDigits(input))
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
			exit (0);
		if (!input.empty())
			return (input);
		std::cout << RED << "Input cannot be empty.  Please try again.\n"
				  << RESET;
	}
}

bool	PhoneBook::confirmSave() const
{
	std::string input;
	std::cout << YEL << "Save this contact? Type YES to save, NO to cancel.\n"
			  << RESET;

	while (true)
	{
		std::cout << YEL "> " << RESET;
		if (!std::getline(std::cin, input))
			exit (0);
		if (input == "YES" || input == "yes")
			return (true);
		if (input == "NO" || input == "no")
			return (false);
		std::cout << "Invalid input. Please type YES or NO.\n";
	}
}

void	PhoneBook::printContactSummary(const Contact& contact) const
{
	std::cout << YEL << "You entered:\n" << RESET;
	std::cout << "First Name    : " << contact.getFirstName() << "\n"
			  << "Last Name     : " << contact.getLastName() << "\n"
			  << "Nickname      : " << contact.getNickName() << "\n"
			  << "Phone Number  : " << contact.getPhoneNumber() << "\n"
			  << "Darkest Secret: " << contact.getDarkestSecret() << "\n";
}

bool	PhoneBook::confirmReplacement(const Contact& oldContact) const
{
	std::string input;
	
	std::cout << "The phonebook is full. This will replace the oldest contact:\n";
	printContactSummary(oldContact);
	std::cout << "Type YES to replace, NO to cancel.\n";

	while (true)
	{
		std::cout << YEL "> " << RESET;
		if (!std::getline(std::cin, input))
			exit (0);
		if (input == "YES" || input == "yes")
			return (true);
		if (input == "NO" || input == "no")
			return (false);
		std::cout << "Invalid input. Please type YES or NO.\n";
	}
}

void	PhoneBook::addContact()
{
	std::string first = promptName("Enter first name");
	std::string last = promptName("Enter last name");
	std::string nick = promptName("Enter nickname");
	std::string phone = promptPhoneNumber("Enter phone number");
	std::string secret = promptNonEmpty("Enter darkest secret");

	// temporarily store contact information
	Contact temp;
	temp.setContact(first, last, nick, phone, secret);
	//show what they typed
	printContactSummary(temp);

	if (!confirmSave())
		return ;
	if (_totalContacts == 8)
	{
		if (!confirmReplacement(_contacts[_nextIndex]))
			return ;
	}

	//save to array
	_contacts[_nextIndex].setContact(first, last, nick, phone, secret);
	//update circular index
	_nextIndex = (_nextIndex + 1) % 8;
	
	if (_totalContacts < 8)
		_totalContacts++;
}
