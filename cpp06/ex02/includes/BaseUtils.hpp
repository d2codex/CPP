/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseUtils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 01:02:17 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/27 01:02:31 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/**
 * @enum Type
 * @brief Represents the runtime type of objects derived from Base.
 *
 * TYPE_A: Object is of class A
 * TYPE_B: Object is of class B
 * TYPE_C: Object is of class C
 * TYPE_UNKNOWN: Pointer is null or type cannot be determined
 */
enum Type
{
	TYPE_A,
	TYPE_B,
	TYPE_C,
	TYPE_UNKNOWN,
};

Base*	generate(void);
Type	getType(Base* p);
Type	getType(Base& p);
void	identify(Base* p);
void	identify(Base& p);
