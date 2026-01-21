/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:22:24 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/21 18:22:26 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "colors.hpp"
#include <string>
#include <iostream>

/* Debug macro: enabled only when -DDBUG is passed to compiler */
#ifdef DBUG
#define DBG(x) x
#else
#define DBG(x)
#endif

/* macros for logging -string input only */
#define LOG_DEBUG(msg)   Logger::debug(msg)
#define LOG_INFO(msg)    Logger::info(msg)
#define LOG_WARNING(msg) Logger::warning(msg)
#define LOG_ERROR(msg)   Logger::error(msg)

/**
 * @brief Simple static logger supporting multiple log levels.
 *
 * The logger is static-only; instantiation is disabled.
 */
class Logger
{
public:
	/* Supported log levels */
	enum logLevel
	{
		INVALID = -1,
		DEBUG = 0,
		INFO = 1,
		WARNING = 2,
		ERROR = 3,
		NONE = 4,
	};

	/* Set the current log threshold */
	static void	setThreshold(logLevel level);

	/* Log functions */
	static void debug(const std::string& message);
	static void info(const std::string& message);
	static void warning(const std::string& message);
	static void error(const std::string& message);

	/* Convert string to logLevel enum */
	static logLevel stringToLevel(const std::string& levelStr);

private:
	Logger (); // prevent instantiation
	
	static	logLevel _threshold;

/* Print the log if level >= threshold */
	static void	writeLog(const std::string& prefix,
						 const std::string& message,
						 logLevel level);
};

#endif
