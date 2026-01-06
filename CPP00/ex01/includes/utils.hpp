/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:43:34 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/06 23:43:36 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

// String manipulation
std::string intToString(int n);
void		toUpperCase(std::string& str);

// user interaction
bool		promptYesNo(const std::string& message);

# endif
