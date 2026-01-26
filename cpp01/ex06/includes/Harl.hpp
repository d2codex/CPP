/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:02:00 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/19 11:02:01 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

/**
 * @class Harl
 * @brief Prints complaint messages at different severity levels.
 *
 * The class contains four message methods and a dispatcher that prints
 * messages from a given level and above.
 */
class Harl
{
public:
	void	complainLevel(std::string level);

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif
