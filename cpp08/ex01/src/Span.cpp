/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:09:13 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/11 09:09:18 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Logger.hpp"
#include <algorithm>
#include <climits>

/**
 * @brief Constructs a Span with a maximum number of integers.
 * @param N Maximum number of integers the Span can store.
 */
Span::Span(unsigned int N) : _maxNumbers(N), _vector(0)
{
	_vector.reserve(N);
	LOG_DEBUG() << "Span Parameterized constructor called";
	LOG_DEBUG() << "max numbers:     " << _maxNumbers;
	LOG_DEBUG() << "vector size:     " << _vector.size();
	LOG_DEBUG() << "vector capacity: " << _vector.capacity();
}

/**
 * @brief Copy constructor for Span.
 * @param other Span instance to copy from.
 */
Span::Span(const Span& other) :
	_maxNumbers(other._maxNumbers),
	_vector(other._vector)
{
	LOG_DEBUG() << "Span copy constructor called"; 
	LOG_DEBUG() << "(copy) max numbers:     " << _maxNumbers;
	LOG_DEBUG() << "(copy) vector size:     " << _vector.size();
	LOG_DEBUG() << "(copy) vector capacity: " << _vector.capacity();
}

/**
 * @brief Assignment operator for Span.
 * @param other Span instance to assign from.
 * @return Reference to this Span.
 */
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxNumbers = other._maxNumbers;
		_vector = other._vector;
	}
	else
		LOG_WARNING() << "Span self-assignment ignored";

	LOG_DEBUG() << "Span assignment operator called"; 
	LOG_DEBUG() << "(assign) max numbers:     " << _maxNumbers;
	LOG_DEBUG() << "(assign) vector size:     " << _vector.size();
	LOG_DEBUG() << "(assign) vector capacity: " << _vector.capacity();

	return (*this);
}

/**
 * @brief Destructor for Span.
 */
Span::~Span()
{
	LOG_DEBUG() << "Span deconstructor called";
}

/**
 * @brief Adds a single number to the Span.
 * Throws SpanFullException if Span is full.
 * @param n Number to add.
 */
void	Span::addNumber(int n)
{
	if (_vector.size() >= _maxNumbers)
		throw SpanFullException();

	_vector.push_back(n);

	LOG_DEBUG() << "(add) vector size:     " << _vector.size();
	LOG_DEBUG() << "(add) vector capacity: " << _vector.capacity();
}

/**
 * @brief Computes the shortest span between numbers in the Span.
 * The method first creates a copy of the stored numbers and sorts it.
 * Then it iterates pairwise to find the minimum difference between
 * consecutive elements.
 *
 * Throws NoSpanException if fewer than 2 numbers are stored.
 *
 * @return Shortest span as unsigned int.
 * @note Time complexity: O(n log n) due to sorting, where n is the
 *       number of elements in the Span.
 */
unsigned int	Span::shortestSpan() const
{
	if (_vector.size() < 2)
		throw NoSpanException();

	std::vector<int> tmp(_vector);
	std::sort(tmp.begin(), tmp.end());


	long long shortest = LLONG_MAX;
	for (size_t i = 0; i < tmp.size() - 1; i++)
	{
		long long	diff = static_cast<long long>(tmp[i + 1]) -
						   static_cast<long long>(tmp[i]);
		if (diff < shortest)
			shortest = diff;
	}
	LOG_INFO() << "Shortest span: " << static_cast<unsigned int>(shortest);
	return (static_cast<unsigned int>(shortest));
}

/**
 * @brief Computes the longest span between numbers in the Span.
 * The method finds the minimum and maximum values in the stored numbers
 * and calculates their difference.
 *
 * Throws NoSpanException if fewer than 2 numbers are stored.
 *
 * @return Longest span as unsigned int.
 * @note Time complexity: O(n) to find min and max, where n is the number
 *       of elements in the Span.
 */
unsigned int	Span::longestSpan() const
{
	if (_vector.size() < 2)
		throw NoSpanException();
	
	std::vector<int>::const_iterator min = std::min_element(_vector.begin(), _vector.end());
	std::vector<int>::const_iterator max = std::max_element(_vector.begin(), _vector.end());

	long long longest = static_cast<long long>(*max) - static_cast<long long>(*min);
	LOG_INFO() << "Longest span: " << static_cast<unsigned int>(longest);

	return (static_cast<unsigned int>(longest));
}

/**
 * @brief Prints all stored numbers in the Span with their indices.
 */
void	Span::printVector() const
{
	for (unsigned int i = 0; i < _vector.size(); i++)
		std::cout << "index[" << i << "]: " << _vector.at(i) << '\n';
}
