
#include "Logger.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>

/**
 * @brief Initialize default log threshold.
 *
 * Default threshold allows all messages (DEBUG and above).
 */
Logger::logLevel Logger::_threshold = Logger::DEBUG;


/**
 * @brief Set the minimum log level to print.
 *
 * Messages below this level are ignored.
 */
void Logger::setThreshold(logLevel level)
{
	_threshold = level;
}

/**
 * @brief Print a log message if allowed by threshold.
 *
 * @param prefix  Colored level prefix (e.g. "[INFO] ").
 * @param message The message to print.
 * @param level   The message log level.
 */
void	Logger::writeLog(const std::string& prefix,
							 const std::string& message, logLevel level)
{
	if (level >= _threshold)
		std::cout << prefix << message << std::endl;
}

/**
 * @brief Log a DEBUG message.
 */
void	Logger::debug(const std::string& message)
{
	writeLog(YEL("[DEBUG] "), message, DEBUG);
}


/**
 * @brief Log an INFO message.
 */
void	Logger::info(const std::string& message)
{
	writeLog(BLU("[INFO] "), message, INFO);
}

/**
 * @brief Log a WARNING message.
 */
void	Logger::warning(const std::string& message)
{
	writeLog(MAG("[WARNING] "), message, WARNING);
}


/**
 * @brief Log an ERROR message.
 */
void	Logger::error(const std::string& message)
{
	writeLog(RED("[ERROR] "), message, ERROR);
}

/**
 * @brief Convert a string to a logLevel enum.
 *
 * Case-insensitive conversion. Returns INVALID if unknown.
 */
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
