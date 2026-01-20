#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "colors.hpp"
#include <string>
#include <iostream>

#define LOG_DEBUG(msg)   Logger::debug(msg)
#define LOG_INFO(msg)    Logger::info(msg)
#define LOG_WARNING(msg) Logger::warning(msg)
#define LOG_ERROR(msg)   Logger::error(msg)

class Logger
{
public:
	enum logLevel
	{
		INVALID = -1,
		DEBUG = 0,
		INFO = 1,
		WARNING = 2,
		ERROR = 3,
		NONE = 4,
	};

	static void	setThreshold(logLevel level);

	// log functions
	static void debug(const std::string& message);
	static void info(const std::string& message);
	static void warning(const std::string& message);
	static void error(const std::string& message);

	// utils
	static logLevel stringToLevel(const std::string& levelStr);

private:
	Logger (); // prevent instantiation
	
	static	logLevel _threshold;

	static void	writeLog(const std::string& prefix,
					 const std::string& message, int level);
};

#endif
