#include "Logger.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>

Logger::logLevel Logger::_threshold = Logger::DEBUG;

void Logger::setThreshold(logLevel level)
{
	_threshold = level;
}

void	Logger::writeLog(const std::string& prefix,
							 const std::string& message, int level)
{
	if (level >= _threshold)
		std::cout << prefix << message << std::endl;
}

void	Logger::debug(const std::string& message)
{
	writeLog(YEL "[DEBUG] " RESET, message, 0);
}

void	Logger::info(const std::string& message)
{
	writeLog(BLU "[INFO] " RESET, message, 1);
}

void	Logger::warning(const std::string& message)
{
	writeLog(MAG "[WARNING] " RESET, message, 2);
}

void	Logger::error(const std::string& message)
{
	writeLog(RED "[ERROR] " RESET, message, 3);
}

Logger::logLevel	Logger::stringToLevel(const std::string& levelStr)
{
	std::string level = levelStr;
	for (std::string::size_type i = 0; i < level.size(); i++)
			level[i] = std::toupper(static_cast<unsigned char>(level[i]));
	
	if (level == "DEBUG")
		return (DEBUG);
	if (level == "INFO")
		return (INFO);
	if (level == "WARNING")
		return (WARNING);
	if (level == "ERROR")
		return (ERROR);
	if (level == "NONE")
		return (NONE);
	return (INVALID); //default
}
