#include "replace.hpp"
#include "colors.hpp"
#include <iostream>
#include <fstream>
#include <string>

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

int	replaceFile(const std::string& filename,
			    const std::string& s1, const std::string& s2)
{
	std::ifstream	inFile(filename.c_str());
	std::ofstream	outFile((filename + ".replace").c_str(), std::ios::trunc);

/*	//explicit version
	std::ofstream outFile; //create the stream object
	//std::ios::out implies create if not exists
	outFile.open(filename + ".replace", std::ios::out | std::ios::trunc);
*/
	if (!inFile || !outFile)
	{
		std::cerr << RED "Error: file could not be opened\n" RESET;
		return (1);
	}
	std::string line;
	bool	firstLine = true;
	while (std::getline(inFile, line))
	{
		if (!firstLine)
			outFile << '\n';
		std::string modifiedLine = replaceLine(line, s1, s2);
		DBUG(std::cout << modifiedLine <<  '\n';)
		outFile << modifiedLine;
		
		if (!outFile)
		{
			std::cout << "outfile bad\n";
			return (1);
		}
		firstLine = false;
	}
	if (inFile.bad())
	{
		std::cout << "infile bad\n";
		return (1);
	}
	return (0);
}
