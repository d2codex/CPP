/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:22:48 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:22:50 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <cctype>
#include <string>

/**
 * @brief Check if a string is empty or only whitespace.
 *
 * @param str The string to validate.
 * @return true if the string is empty or contains only whitespace.
 * @return false otherwise.
 */
bool	isBlank(const std::string& str)
{
	if (str.empty())
		return (true);
	
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			return (false);
	}
	
	return (true);
}
