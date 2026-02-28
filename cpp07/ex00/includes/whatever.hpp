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

template<typename T>
const T& min(const T& a, const T& b)
{
	LOG_DEBUG() << "  input first: " << a << ", " << &a;
	LOG_DEBUG() << " input second: " << b << ", " << &b;

	if (b > a)
	{
		LOG_DEBUG() << " min is first: " << a << ", " << &a;
		return (a);
	}
	LOG_DEBUG() << "min is second: " << b << ", " << &b;
	return (b);
	//return (b > a ? a : b);
}

template<typename T>
const T& max(const T& a, const T& b)
{
	LOG_DEBUG() << "  input first: " << a << ", " << &a;
	LOG_DEBUG() << " input second: " << b << ", " << &b;
	if (b < a)
	{
		LOG_DEBUG() << " max is first: " << a << ", " << &a;
		return (a);
	}
	LOG_DEBUG() << "max is second: " << b << ", " << &b;
	return (b);
	//return (b > a ? a : b);
}
