/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:31:04 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/21 18:31:06 by diade-so         ###   ########.fr       */
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
		std::cout << CYN("Usage: ./bin/Fixed <log mode>\n")
				  << "Log modes: <debug> <info> <warning> <error> <none>\n";
		return (1);
	}
	Logger::logLevel level = Logger::stringToLevel(argv[1]);
	if (level == Logger::INVALID)
	{
		std::cout << RED("Error: Invalid log mode\n")
				  << "Log modes: <debug> <info> <warning> <error> <none>\n";
		return (1);
	}
	Logger::setThreshold(level);

	Fixed a;
	Fixed const b( 10 ); //int constructor
	Fixed const c( 42.42f ); // float constructor
	Fixed const d( b ); // copy constructor

	a = Fixed( 1234.4321f ); //float constructor

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
