/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:37:07 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 10:37:09 by diade-so         ###   ########.fr       */
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
	NONE = 0,
	DEBUG = 1,
	INFO = 2,
	WARNING = 3,
	ERROR = 4,
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
	Logger();
	Logger(const Logger& other);
	Logger& operator=(const Logger&);
	~Logger();
	
	/* Singleton instance */
	static		Logger& get();
	
	/* Flush a completed message */
	void		flush(const std::string& prefix,
					  const std::string& message,
					  logLevel level);

	/* Set the current log threshold */
	void		setThreshold(logLevel level);
	logLevel	threshold() const;

	/* RAII factory for LogLine */
	LogLine		makeLine(const std::string& prefix, logLevel level);

	/* Convert string to logLevel enum */
	static		logLevel stringToLevel(const std::string& levelStr);

private:
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
	LogLine(const LogLine& other);
	LogLine& operator=(const LogLine& other);
	~LogLine();

	template<typename T>
	LogLine& operator<<(const T& value)
	{
		_stream << value;
		return (*this);
	}

private:
	LogLine();
	Logger&				_logger;
	std::ostringstream	_stream;
	std::string			_prefix;
	logLevel			_level;
};

/* log macros */
#ifdef DBUG
#define LOG_DEBUG()		Logger::get().makeLine(yel("[DEBUG] "), DEBUG)
#else
#define LOG_DEBUG()		Logger::get().makeLine(yel(""), NONE)
#endif

#define LOG_INFO()		Logger::get().makeLine(blu("[INFO] "), INFO)
#define LOG_WARNING()	Logger::get().makeLine(mag("[WARNING] "), WARNING)
#define LOG_ERROR()		Logger::get().makeLine(red("[ERROR] "), ERROR)
