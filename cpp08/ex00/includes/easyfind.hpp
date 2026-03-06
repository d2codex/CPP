#pragma once

#include <algorithm>
#include <stdexcept>
#include "Logger.hpp"

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("Value not found");
	
	LOG_DEBUG() << "Value: " << value << " found at position "
				<< std::distance(container.begin(), it);

	return (it);
}
