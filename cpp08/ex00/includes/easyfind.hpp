/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 08:55:54 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/11 08:55:56 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>
#include "Logger.hpp"

/**
 * @brief Finds a value in a container using std::find.
 *
 * Searches the container for the specified value and returns an iterator
 * to the first occurrence.
 *
 * @tparam T Container type supporting begin(), end(), and iterators.
 * @param container Container to search.
 * @param value Value to locate in the container.
 * @return Iterator pointing to the found element.
 *
 * @throws std::runtime_error If the value is not found in the container.
 */
template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("Value not found");
	
	LOG_DEBUG() << "Value: " << value << " found at position "
				<< std::distance(container.begin(), it);

	return (it);
}
