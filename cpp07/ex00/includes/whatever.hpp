#pragma once

#include "Logger.hpp"

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
	//return (b > a ? a : b);
}

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
	//return (b > a ? a : b);
}
