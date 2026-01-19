/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:18:13 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/19 09:18:15 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>
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
