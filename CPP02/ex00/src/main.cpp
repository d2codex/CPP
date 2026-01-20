/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:18:26 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/20 17:18:30 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "colors.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << CYN "Usage: ./bin/Fixed <log mode>\n" RESET
				  << "Log modes: <debug> <info> <warning> <error> <none>\n";
		return (1);
	}
	Logger::logLevel level = Logger::stringToLevel(argv[1]);
	if (level == Logger::INVALID)
	{
		std::cout << RED "Error: Invalid log level\n" RESET;
		return (1);
	}
	Logger::setThreshold(level);

	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}
