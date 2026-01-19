#include "Harl.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>
#include <iomanip>

#define COL_WIDTH 9

void	Harl::debug(void)
{
	std::cout << YEL << std::setw(COL_WIDTH) << "[DEBUG]" << RESET
			  << " I love having extra bacon for my burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << BLU << std::setw(COL_WIDTH) << "[INFO]" << RESET
			  << " You didn’t put enough bacon in my burger!\n";
}

void	Harl::warning(void)
{
	std::cout << MAG << std::setw(COL_WIDTH) << "[WARNING]" << RESET 
			  << " I think I deserve to have some extra bacon for free.\n";
}

void	Harl::error(void)
{
	std::cout << RED << std::setw(COL_WIDTH) << "[ERROR]" << RESET
			  << " This is unacceptable! I want to speak to the manager now. \n";
}

void	Harl::complain(std::string level)
{
	// we create an array of pointers *functions[]
	// to member functions of Harl::
	// this returns void and takes no arguments
	void (Harl::*functions[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	//here we create another array assigning a specific level to 
	//each index.  
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t numLevels = sizeof(levels) / sizeof(levels[0]);
	//when complain is called it will see if 'level' matches
	//any one of the levels: DEBUG, INFO, WARNING, ERROR
	//if it does, it will call the function from the *functions[] table
	//ex: level = INFO 
	//Harl::*functions[1] = &Harl::info (this is the function that gets called)
	for (size_t i = 0; i < numLevels; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "No matching levels detected\n";
}
