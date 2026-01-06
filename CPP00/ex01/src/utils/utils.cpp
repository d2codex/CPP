#include "utils.hpp"
#include "colors.hpp"
#include <cctype>
#include <sstream>
#include <iostream>

std::string intToString(int n)
{
	std::ostringstream	oss;

	oss << n;
	return (oss.str());
}

void	toUpperCase(std::string& str)
{
	for (std::string::size_type i = 0; i < str.size(); ++i)
		str[i] = std::toupper(str[i]);
}

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
