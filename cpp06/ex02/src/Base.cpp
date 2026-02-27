/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 00:59:06 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/27 00:59:39 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Logger.hpp"

/**
 * @brief Virtual destructor for Base.
 */
Base::~Base()
{
	LOG_DEBUG() << "Base destructor called";
}
