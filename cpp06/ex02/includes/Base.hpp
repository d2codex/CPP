/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 01:02:34 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/27 01:03:03 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/**
 * @class Base
 * @brief Base class for polymorphic hierarchy.
 *
 * Provides a virtual destructor to ensure proper deletion of derived 
 * objects via Base pointers.
 */
class Base
{
public:
	virtual ~Base();
};
