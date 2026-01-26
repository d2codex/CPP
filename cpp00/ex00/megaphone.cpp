/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:02:55 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/03 18:39:13 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/**
 * @brief Prints a C-string in uppercase to standard output.
 *
 * Each character of the string is converted to uppercase using std::toupper.
 * 
 * @param str The C-string to be printed in uppercase.
 *
 * @details
 * We cast each char to unsigned char before passing to std::toupper to 
 * avoid undefined behavior if char is signed and negative. 
 * std::toupper returns an int, so we cast back to char for correct output.
 */
static void	printUpper(char *str)
{
	int i = 0;

	while(str[i])
	{
		unsigned char c = static_cast<unsigned char>(str[i]);
		std::cout << static_cast<char>(std::toupper(c));
		i++;
	}
}

/**
 * @brief Entry point for the megaphone program.
 *
 * Prints all command-line arguments in uppercase. If no arguments are given,
 * prints a default loud message.
 *
 * @details
 * We use '\n' instead of std::endl to avoid flushing the output buffer 
 * on each line, which is more efficient for simple programs.
 *
 * @param argc Argument count.
 * @param argv Argument values (C-strings).
 * @return int 0 on success, 1 if no arguments are provided.
 */
int	main(int argc, char **argv)
{
	int	i = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	while (i < argc)
	{
		printUpper(argv[i]);
		i++;
	}
	std::cout << '\n';
	return (0);
}
