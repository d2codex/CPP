#include "replace.hpp"
#include "colors.hpp"
#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << CYN "usage: ./bin/replace <string1> <string2>\n" RESET;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (!validateArgs(filename, s1, s2))
		return (1);


	return (0);
}
