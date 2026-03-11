/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 08:57:20 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/11 09:01:25 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <climits>

/**
 * @brief Stores a fixed number of integers and computes spans.
 *
 * The Span class allows adding integers up to a maximum N and
 * provides methods to find the shortest and longest span
 * (difference) between any two stored numbers.
 *
 * Numbers can be added individually or using a range of iterators,
 * allowing data to be read from any container type (vector, list, etc.).
 */
class Span
{
public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	//exceptions
	class SpanFullException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Span is full");
			}
	};
	class NoSpanException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("No span possible. Must have at least 2 numbers.");
			}
	};

	// methods
	void			addNumber(int n);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	template<typename Iterator>
	void			addNumber(Iterator begin, Iterator end)
	{
		for(; begin != end; ++begin)
			addNumber(*begin);
	}

	//utility functions
	void	printVector() const;

private:
	unsigned int		_maxNumbers;
	std::vector<int>	_vector;
};

/**
 * @brief Generates a container filled with random integers.
 *
 * This function creates a container of type Container with `n`
 * random integers. Each integer can be positive or negative.
 * The function supports any container type that has push_back().
 *
 * @tparam Container Type of the container to generate (e.g., vector, list).
 * @param n Number of random integers to generate (max 2,000,000).
 * @return Container filled with random integers.
 */
template<typename Container>
Container generateRandomNumbers(size_t n)
{
	Container c;
	
	const size_t MAX_SIZE = 2000000;
	if (n > MAX_SIZE)
		n = MAX_SIZE;

	for (size_t i = 0; i < n; i++)
	{
		int num = rand() % n;
		if (rand() % 2)
			num = -num;
		c.push_back(num);
	}
	return (c);
}
