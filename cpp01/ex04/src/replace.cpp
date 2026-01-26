/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:41:46 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:42:03 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include "colors.hpp"
#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Replace all occurrences of s1 with s2 in a line.
 *
 * This function searches the input line for every occurrence of s1,
 * and builds a new string with s2 inserted instead.
 *
 * @param line The input line to process.
 * @param s1 The substring to search for.
 * @param s2 The substring to replace s1 with.
 * @return std::string The modified line.
 */
std::string replaceLine(const std::string& line,
						const std::string& s1, const std::string& s2)
{
	std::string result;
	std::size_t pos = 0;
	std::size_t found;

	while ((found = line.find(s1, pos)) != std::string::npos)
	{
		result += line.substr(pos, found - pos);
		result += s2;
		pos = found +s1.length();
	}
	result += line.substr(pos);
	return (result);
}

/**
 * @brief Replace occurrences of s1 with s2 in a file.
 *
 * Opens the given file, creates a new file with ".replace" appended,
 * and writes the modified lines to it. Returns 0 on success, 1 on
 * any error (opening file, read/write errors, etc.).
 *
 * @param filename Name of the file to read.
 * @param s1 The string to search for.
 * @param s2 The string to replace s1 with.
 * @return int 0 on success, 1 on error.
 */
int	replaceFile(const std::string& filename,
			    const std::string& s1, const std::string& s2)
{
	std::ifstream	inFile(filename.c_str());

/*	//explicit version
	std::ofstream outFile; //create the stream object
	//std::ios::out is an flag for create if not exists
	outFile.open(filename + ".replace", std::ios::out | std::ios::trunc);
*/
	if (!inFile)
	{
		std::cerr << RED "Error: cannot open input file "
				  << filename << RESET << '\n';
		return (1);
	}
	std::ofstream	outFile((filename + ".replace").c_str(), std::ios::trunc);
	if (!outFile)
	{
		std::cerr << RED "Error: cannot create output file"
				  << filename << ".replace" << RESET << '\n';
	}
	std::string line;
	while (std::getline(inFile, line))
	{
		std::string modifiedLine = replaceLine(line, s1, s2);
		DBUG(std::cout << modifiedLine << '\n';)
		outFile << modifiedLine << '\n';
		if (!outFile)
		{
			std::cerr << "Error. Could not write to "
					  << filename << ".replace\n" << RESET;
			return (1);
		}
	}
	if (inFile.bad())
	{
		std::cerr << "Error: failure while reading file: "
				  << filename << RESET << '\n';
		return (1);
	}
	return (0);
}
