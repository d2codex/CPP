/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:48:29 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/04 09:48:30 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

/**
 * @brief Applies a function to each element of an array.
 *
 * @tparam T Type of the array elements.
 * @tparam F Type of the function to apply
 *         (can be a function or a function template).
 * @param array Pointer to the first element of the array.
 * @param len Length of the array (const value as per subject instructions).
 * @param func Function to apply to each element. Can take `T&` or `const T&`.
 */
template<typename T, typename F>
void	iter(T* array, const size_t N, F function)
{
	if (!array)
		return ;
	for(size_t i = 0; i < N; i++)
		function(array[i]);
}
