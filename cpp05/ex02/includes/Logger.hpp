/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:44:36 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/18 10:44:37 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "colors.hpp"
#include <string>
#include <sstream>
#include <iostream>

/* Supported log levels */
enum logLevel
{
	INVALID = -1,
	DEBUG = 0,
	INFO = 1,
	WARNING = 2,
	ERROR = 3,
};

class LogLine;

/**
 * @class Logger
 * @brief Singleton logger supporting multiple log levels and RAII.
 *
 * Logger manages a single logging instance, allowing messages to be
 * streamed via LogLine objects. It supports thresholds to filter
 * messages, converting string levels to enum, and flushes messages
 * to stdout with optional color-coded prefixes.
 */
class Logger
{
public:
	
	/* Singleton instance */
	static		Logger& get();
	
	/* Flush a completed message */
	void		flush(const std::string& prefix,
					  const std::string& message,
					  logLevel level);

	/* Set the current log threshold */
	void		setThreshold(logLevel level);
	logLevel	threshold() const;

	/* Convert string to logLevel enum */
	static		logLevel stringToLevel(const std::string& levelStr);

private:
	Logger();
	~Logger();

	Logger(const Logger&);
	Logger& operator=(const Logger&);

	logLevel _threshold;
};

/**
 * @class LogLine
 * @brief RAII helper to build and flush a log message.
 *
 * LogLine accumulates streamed values into an internal buffer. When
 * destroyed, it automatically flushes the message through the
 * associated Logger, respecting the log level and threshold.
 */
class LogLine
{
public:
	LogLine(Logger& logger, const std::string& prefix, logLevel level);
	~LogLine();

	template<typename T>
	LogLine& operator<<(const T& value)
	{
		_stream << value;
		return (*this);
	}

private:
	LogLine();
	LogLine(const LogLine&);
	LogLine& operator=(const LogLine&);

	Logger&				_logger;
	std::ostringstream	_stream;
	std::string			_prefix;
	logLevel			_level;
};

/* log macros */
#ifdef DBUG
#define LOG_DEBUG()		LogLine(Logger::get(), yel("[DEBUG] "), DEBUG)
#else
#define LOG_DEBUG()		LogLine(Logger::get(), yel(""), DEBUG)
#endif

#define LOG_INFO()		LogLine(Logger::get(), blu("[INFO] "), INFO)
#define LOG_WARNING()	LogLine(Logger::get(), mag("[WARNING] "), WARNING)
#define LOG_ERROR()		LogLine(Logger::get(), red("[ERROR] "), ERROR)
