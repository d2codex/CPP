/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:40:00 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/18 23:40:03 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#ifdef DEBUG
#define DBUG(x) x
#else
#define DBUG(x)
#endif

#include <string>

std::string replaceLine(const std::string& line,
						const std::string& s1, const std::string& s2);
int			replaceFile(const std::string& filename,
						const std::string& s1, const std::string& s2);

#endif
