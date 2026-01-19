#include "Harl.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>
#include <iomanip>

#define COL_WIDTH 9

/**
 * @brief Print a debug-level message.
 *
 * Outputs a message describing extra detail or low-priority information.
 */
void	Harl::debug(void)
{
	std::cout << YEL << std::setw(COL_WIDTH) << "[DEBUG]" << RESET
			  << " I love having extra bacon for my burger. I really do!\n";
}


/**
 * @brief Print an info-level message.
 *
 * Outputs a general informational message about a minor issue.
 */
void	Harl::info(void)
{
	std::cout << BLU << std::setw(COL_WIDTH) << "[INFO]" << RESET
			  << " You didn’t put enough bacon in my burger!\n";
}

/**
 * @brief Print a warning-level message.
 *
 * Outputs a message indicating a potential problem or complaint.
 */
void	Harl::warning(void)
{
	std::cout << MAG << std::setw(COL_WIDTH) << "[WARNING]" << RESET 
			  << " I think I deserve to have some extra bacon for free.\n";
}

/**
 * @brief Print an error-level message.
 *
 * Outputs a critical message indicating an unacceptable situation.
 */
void	Harl::error(void)
{
	std::cout << RED << std::setw(COL_WIDTH) << "[ERROR]" << RESET
			  << " This is unacceptable! I want to speak to the manager now. \n";
}

/**
 * @brief Dispatch a complaint based on the given level.
 *
 * Matches the input level against known levels and calls the
 * corresponding member function. Prints a message if no match
 * is found.
 *
 * @param level Complaint severity ("DEBUG", "INFO", "WARNING", "ERROR").
 */
void Harl::complainLevel(std::string level)
{

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	lvl = -1;
	size_t	numLevels = sizeof(levels) / sizeof(levels[0]);
	for (size_t i = 0; i < numLevels; i++)
	{
		if (levels[i] == level)
			lvl = i;
	}
	
	switch (lvl)
	{
		case 0:
			debug();
			/* fallthrough */
		case 1:
			info();
			/* fallthrough */
		case 2:
			warning();
			/* fallthrough */
		case 3:
			error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}

