/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 00:58:23 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/27 00:58:24 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "BaseUtils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "colors.hpp"
#include <iostream>
#include <cstdlib>

/**
 * @brief Generate a random derived instance (A, B, or C).
 * Uses std::rand() to select a type and allocates it on the heap.
 * @return Pointer to newly allocated Base-derived object.
 */
Base* generate(void)
{
	int random = std::rand() % 3;

	switch(random)
	{
		case 0: return (new A);
		case 1: return (new B);
		default: return (new C);
	}
}

/**
 * @brief Identify dynamic type from a Base pointer.
 * Uses dynamic_cast on pointer. Returns TYPE_UNKNOWN if null
 * or no match is found.
 * @param p Pointer to Base object.
 * @return Corresponding Type enum.
 */
Type	getType(Base* p)
{
	if (!p)
		return (TYPE_UNKNOWN);
	if (dynamic_cast<A*>(p))
		return (TYPE_A);
	else if (dynamic_cast<B*>(p))
		return (TYPE_B);
	else if (dynamic_cast<C*>(p))
		return (TYPE_C);
	else
		return (TYPE_UNKNOWN);
}

/**
 * @brief Identify dynamic type from a Base reference.
 * Uses dynamic_cast on reference. Relies on exceptions
 * to detect failed casts.
 * @param p Reference to Base object.
 * @return Corresponding Type enum.
 */
Type	getType(Base& p)
{
    try
	{
        (void)dynamic_cast<A&>(p);
        return TYPE_A;
    }
	catch (...) {}
	try
	{
        (void)dynamic_cast<B&>(p);
        return TYPE_B;
    }
	catch (...) {}
    return TYPE_C;
}

/**
 * @brief Print type of object from Base pointer.
 * Prints a message based on detected type. Handles null pointer.
 * @param p Pointer to Base object.
 */
void identify(Base* p)
{
	Type t = getType(p);
	if (t == TYPE_UNKNOWN)
	{
		std::cout << mag("Pointer is null.\n");
		return ;
	}
	if (t == TYPE_A)
		std::cout << "Base type: A\n";
	else if (t == TYPE_B)
		std::cout << "Base type: B\n";
	else if (t == TYPE_C)
		std::cout << "Base type: C\n";
}

/**
 * @brief Print type of object from Base reference.
 * Assumes valid reference. Prints detected dynamic type.
 * @param p Reference to Base object.
 */
void identify(Base& p)
{
	Type t = getType(p);
	if (t == TYPE_A)
		std::cout << "Base type: A\n";
	else if (t == TYPE_B)
		std::cout << "Base type: B\n";
	else
		std::cout << "Base type: C\n";
}
