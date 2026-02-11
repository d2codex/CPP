/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:37:49 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 10:37:50 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include "colors.hpp"
#include <cstring>


/*****************************************************************************
 *                                   LOGGER                                  *
 *****************************************************************************/

/**
 * @brief Default constructor. Sets threshold to INFO.
 */
Logger::Logger() : _threshold(INFO) {}

/**
 * @brief Copy constructor.
 * @param other Logger to copy from.
 */
Logger::Logger(const Logger& other) : _threshold(other._threshold) {}

/**
 * @brief Copy assignment operator.
 * @param other Logger to copy from.
 * @return Reference to this Logger.
 */
Logger& Logger::operator=(const Logger& other)
{
	if (this != &other)
		_threshold = other._threshold;

	return (*this);
}

/**
 * @brief Destructor.
 */
Logger::~Logger() {}

/**
 * @brief Get the singleton instance of Logger.
 * @return Reference to the single Logger instance.
 */
Logger& Logger::get()
{
	static Logger instance;
	return (instance);
}

/**
 * @brief Flush the message to stdout if it passes threshold.
 * @param prefix String prefix to print before the message.
 * @param message The message content to print.
 * @param level The log level of this message.
 */
void	Logger::flush(const std::string& prefix,
					  const std::string& message,
					  logLevel level)
{
#ifdef DBUG
	bool isDebug = (level == DEBUG);
#else
	bool isDebug = false;
#endif

	// NONE threshold: only DEBUG prints
	if (_threshold == NONE && !isDebug)
		return ;

	// >= threshold filtering
	if (level >= _threshold || isDebug)
		std::cout << prefix << message << std::endl;
}

/**
 * @brief Set the logging threshold.
 * @param level Minimum log level to print.
 */
void	Logger::setThreshold(logLevel level)
{
	_threshold = level;
}

/**
 * @brief Get the current logging threshold.
 * @return Current threshold level.
 */
logLevel	Logger::threshold() const
{
	return (_threshold);
}

/**
 * @brief Create a LogLine for streaming a message.
 * @param prefix Prefix string for the log line.
 * @param level Log level for the line.
 * @return LogLine object for message streaming.
 */
LogLine Logger::makeLine(const std::string& prefix, logLevel level)
{
	return (LogLine(*this, prefix, level));
}

/**
 * @brief Convert string to logLevel enum.
 * @param levelStr String representation of the log level.
 * @return Corresponding logLevel enum, or INVALID if unknown.
 */
logLevel	Logger::stringToLevel(const std::string& levelStr)
{
	std::string level = levelStr;
	for (std::string::size_type i = 0; i < level.size(); i++)
			level[i] = std::toupper(static_cast<unsigned char>(level[i]));
	
	if (level == "NONE")
		return (NONE);
	if (level == "DEBUG")
		return (DEBUG);
	if (level == "INFO")
		return (INFO);
	if (level == "WARNING")
		return (WARNING);
	if (level == "ERROR")
		return (ERROR);
	return (INVALID);
}

/*****************************************************************************
 *                                  LOGLINE                                  *
 *****************************************************************************/

/**
 * @brief Construct a LogLine object for streaming.
 * @param logger Logger instance to flush through.
 * @param prefix Prefix string for this line.
 * @param level Log level of this line.
 */
LogLine::LogLine(Logger& logger, const std::string& prefix, logLevel level) :
	_logger(logger), _prefix(prefix), _level(level)
{}

/**
 * @brief Copy constructor.
 * @param other LogLine to copy from.
 */
LogLine::LogLine(const LogLine& other) :
	_logger(other._logger), _prefix(other._prefix), _level(other._level)
{
	_stream << other._stream.str();
}

/**
 * @brief Copy assignment operator.
 * @param other LogLine to copy from.
 * @return Reference to this LogLine.
 */
LogLine& LogLine::operator=(const LogLine& other)
{
	if (this != &other)
	{
		_prefix = other._prefix;
		_level = other._level;
		_stream.str(other._stream.str());
	}
	return (*this);
}

/**
 * @brief Destructor. Flushes the line to the logger.
 */
LogLine::~LogLine()
{
	_logger.flush(_prefix, _stream.str(), _level);
}
