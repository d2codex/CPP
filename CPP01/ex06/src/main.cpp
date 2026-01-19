#include "Harl.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>

int	main(int argc, char **argv)
{
	Harl harl;
	if (argc != 2)
	{
		std::cout << YEL "Usage: ./harlFilter <level>\n" RESET;
		return (1);
	}
	std::string level = argv[1];
	harl.complainLevel(level);
}
