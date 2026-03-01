/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:38:20 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/01 19:38:21 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Logger.hpp"

/**
 * @brief Swap two values of any type.
 *
 * Uses a temporary variable initialized directly from @p a.
 * This avoids requiring a default constructor and prevents
 * an extra assignment.
 *
 * Example:
 * @code
 * struct Point
 * {
 *     int x, y;
 *     Point(int x, int y) : x(x), y(y) {}
 * };
 *
 * Point a(1, 2);
 * Point b(3, 4);
 * swap(a, b); // OK
 *
 * // T temp; temp = a; would fail (no default ctor)
 * @endcode
 *
 * @tparam T Type supporting copy and assignment.
 * @param a First value.
 * @param b Second value.
 */
template<typename T> 
void	swap(T& a, T& b)
{
	LOG_DEBUG() << "before swap: " << a << ", " << b;

	T temp = a;
	a = b;
	b = temp;

	LOG_DEBUG() << " after swap: " << a << ", " << b;
}

/**
 * @brief Returns the smaller of two values.
 *
 * Compares `a` and `b` and returns a reference to the smaller one.
 *
 * @tparam T Type of the arguments; must support comparison operators.
 * @param a First value.
 * @param b Second value.
 * @return const T& Reference to the smaller value.
 *
 * @note In the debug logs, addresses are printed using static_cast<const void*>.
 *       This is important for types like `char`:
 *       - `operator<<(ostream&, char)` prints the character itself.
 *       - Taking the address of a `char` gives `const char*`, which ostream
 *         interprets as a C-string. If the char is not null-terminated, this
 *         can cause undefined behavior (e.g., printing the same character twice,
 *         garbage, or even crashes).
 *       - Casting to `const void*` ensures the actual memory address is printed
 *         safely for all types.
 */
template<typename T>
const T& min(const T& a, const T& b)
{
	LOG_DEBUG() << "  input first: " << a << ", " << static_cast<const void*>(&a);
	LOG_DEBUG() << " input second: " << b << ", " << static_cast<const void*>(&b);

	if (b > a)
	{
		LOG_DEBUG() << " min is first: " << a << ", " << static_cast<const void*>(&a);
		return (a);
	}
	LOG_DEBUG() << "min is second: " << b << ", " << static_cast<const void*>(&b);
	return (b);
}

/**
 * @brief Returns the greater of two values.
 *
 * Compares @p a and @p b and returns the larger one. The parameters are
 * passed as const references to avoid copying large objects (like
 * std::string, structs, or classes) and to allow using literals directly.
 *
 * @tparam T Type of the values to compare. Must support operator<.
 * @param a First value.
 * @param b Second value.
 * @return const T& Reference to the larger value.
 *
 * @note Returning a const reference avoids unnecessary copies, and
 *       allows calls like max(5, x) without creating temporary objects.
 */
template<typename T>
const T& max(const T& a, const T& b)
{
	LOG_DEBUG() << "  input first: " << a << ", " << static_cast<const void*>(&a);
	LOG_DEBUG() << " input second: " << b << ", " << static_cast<const void*>(&b);
	if (b < a)
	{
		LOG_DEBUG() << " max is first: " << a << ", " << static_cast<const void*>(&a);
		return (a);
	}
	LOG_DEBUG() << "max is second: " << b << ", " << static_cast<const void*>(&b);
	return (b);
}
