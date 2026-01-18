#include "replace.hpp"
#include "colors.hpp"
#include <iostream>
#include <fstream>
#include <string>


bool	validateArgs(const std::string& filename,
				 const std::string& s1,
				 const std::string& s2)
{
	(void)s2;

	//check s1 and s2 not empty
	if (s1.empty())
	{
		std::cerr << RED "Error: Search string cannot be empty\n" RESET;
		return (false);
	}
	//check filename access
//	std::ifstream file(filename.c_str());

	// more explicit way
	std::ifstream file;
	file.open(filename.c_str());

	if (!file)
	{
		std::cerr << RED "Error: Cannot open file\n" RESET;
		return (false);
	}

	DBUG(std::cout << BLU "File successfully opened!\n" RESET;)

	return (true);
}
