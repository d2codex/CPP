/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:18:18 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/19 09:18:38 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#ifdef DEBUG
#define DBUG(x) x
#else
#define DBUG(x)
#endif

#include <string>

/**
 * @class Harl
 * @brief Simple logger that prints complaints at different levels.
 *
 * The class maps a string level to a corresponding message function.
 * Supported levels: DEBUG, INFO, WARNING, ERROR.
 */
class Harl
{
public:
	void	complain(std::string level);

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif
