/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:12:24 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/11 09:13:44 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>
#include <iostream>
#include <iterator>

/**
 * @brief A stack that supports iteration over its elements.
 * Inherits from std::stack and exposes iterators (forward, reverse, const).
 * Maintains normal LIFO behavior for push/pop/top while allowing traversal
 * of the underlying container. Iterators can read from any compatible container.
 *
 * @tparam T Type of elements stored in the stack.
 * @tparam Container Type of underlying container (defaults to std::deque<T>).
 */
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	typedef typename std::stack<T, Container>::container_type	container_type;
	typedef typename container_type::iterator					iterator;
	typedef typename container_type::reverse_iterator			reverse_iterator;
	typedef typename container_type::const_iterator				const_iterator;
	typedef typename container_type::const_reverse_iterator		const_reverse_iterator;

	MutantStack() {}
	MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
	MutantStack& operator=(const MutantStack& other)
	{
		if (this != &other)
			std::stack<T, Container>::operator=(other);
		return (*this);
	}
	~MutantStack() {}

	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }
	
	reverse_iterator rbegin() { return (this->c.rbegin()); }
	reverse_iterator rend() { return (this->c.rend()); }

	const_iterator begin() const { return (this->c.begin()); }
	const_iterator end() const { return (this->c.end()); }

	const_reverse_iterator rbegin() const { return (this->c.rbegin()); }
	const_reverse_iterator rend() const { return (this->c.rend()); }
};

/**
 * @brief Print elements of any container with indices.
 * Iterates from begin() to end() and prints the index and value of
 * each element. Works with any container that provides const iterators.
 *
 * @tparam T Type of the container.
 * @param container The container whose elements will be printed.
 */
template<typename T>
void printElements(const T& container)
{
	typedef typename T::const_iterator const_iterator;
	for(const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << "[" << std::distance(container.begin(), it) << "]: " <<
			*it << '\n';
	}
}
