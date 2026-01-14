/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:15:12 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/14 14:15:15 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "../colors.hpp"

#define LABLE_WIDTH 34

/**
 * @file main.cpp
 * @brief Demonstrates pointers and references with a string.
 *
 * This program creates a string, a pointer to it, and a reference to it.
 * It prints their memory addresses and values, with aligned output
 * and color coding for clarity.
 *
 * @return int Always returns 0.
 */
int	main(void)
{
	// original string
	const std::string str = "HI THIS IS BRAIN";
	// a pointer stores an address
	const std::string* stringPTR = &str;
	// this is just an alias of the original string
	const std::string& stringREF = str;

	// original string address
	std::cout << WHT
			  << std::left << std::setw(LABLE_WIDTH)
			  << "Memory address of str:"
			  << &str << RESET << '\n';

	// to get the address stored inside the pointer
	// just print the value of the ptr
	std::cout << BLU
			  << std::left << std::setw(LABLE_WIDTH)
			  << "Memory address held by stringPTR: "
			  << stringPTR << RESET <<'\n';
	
	// the pointer itself has its own address
	// to access it we do &stringPTR (should be diff from stored address).
	std::cout << CYN
			  << std::left << std::setw(LABLE_WIDTH)
			  << "Memory addr of actual stringPTR: " << &stringPTR
			  << RESET << '\n';

	// treat it just like the original string use &to get the address
	// of the reference, which is the same as the original str
	std::cout << YEL
			  << std::left << std::setw(LABLE_WIDTH)
			  << "Memory address held by stringREF: " << &stringREF
			  << RESET << '\n';
	
	//original value of string
	std::cout << WHT
			  << std::left << std::setw(LABLE_WIDTH)
			  << "Value of str: " << str
			  << RESET << '\n';

	// to get the value of the stored address we must dereference the ptr
	std::cout << BLU 
			  << std::left << std::setw(LABLE_WIDTH)
			  << "Value pointed to by stringPTR: " << *stringPTR
			  << RESET << '\n';
	
	// same here: a reference is an alias, so we acccess the value directly
	std::cout << YEL
			  << std::left << std::setw(LABLE_WIDTH)
			  << "Value pointed to by stringREF: " << stringREF
			  << RESET << '\n';
}
