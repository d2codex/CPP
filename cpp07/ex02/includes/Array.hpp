/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:16:19 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/04 10:16:21 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Logger.hpp"

/**
 * @brief Generic dynamic array container.
 *
 * Provides a dynamically allocated array of type T with deep copy
 * semantics, bounds-checked element access, and size tracking.
 *
 * Supports default and parameterized construction, copy construction,
 * and assignment. Ensures safe memory management using new[]/delete[].
 *
 * @tparam T Type of elements stored in the array.
 */
template<typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	T&				operator[](unsigned int index);
	const T&		operator[](unsigned int index) const;
	
	unsigned int	size() const;

private:
	T*				_array;
	unsigned int	_size;
};

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

/**
 * @brief Default constructor.
 * Creates an empty array with size 0 and a null data pointer.
 */
template<typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
	LOG_DEBUG() << "Array default constructor called";
}

/**
 * @brief Parameterized constructor.
 * Allocates an array of n elements and value-initializes them.
 * The () ensures built-in types (e.g., int, float) are set to 0
 * instead of left uninitialized (garbage values).
 *
 * @param n Number of elements to allocate.
 */
template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
	LOG_DEBUG() << "Array parameter constructor called";
	LOG_DEBUG() << "Array size: " << _size;
}

/**
 * @brief Copy constructor.
 * Performs a deep copy of the source array.
 * Allocates new storage and copies each element individually.
 *
 * Does not delegate to operator= (*this = other) because _array
 * is uninitialized at this point. Calling operator= would attempt
 * to delete[] an uninitialized pointer, leading to undefined behavior.
 *
 * @param other Array to copy from.
 */
template<typename T>
Array<T>::Array(const Array& other) : _array(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
	LOG_DEBUG() << "Array Copy constructor called";
	LOG_DEBUG() << "Array size: " << _size;
}

/**
 * @brief Copy assignment operator.
 * Replaces the contents of the current array with a deep copy of
 * another array.
 *
 * Allocates new storage first, then deletes the old storage.
 * This order is critical: if allocation fails and throws, the
 * original data remains intact (strong exception safety).
 * Deleting first would risk losing data or leaving the object
 * in an invalid state if allocation or copying fails.
 *
 * @param other Array to copy from.
 * @return Reference to the assigned array.
 */
template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T* new_array = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++)
			new_array[i] = other._array[i];
		delete[] _array;
		_array = new_array;
		_size = other._size;

		LOG_DEBUG() << "Array assignment operator called";
		LOG_DEBUG() << "Array size: " << _size;
	}
	else
		LOG_DEBUG() << "Self-assignment ignored";
	return (*this);
}

/**
 * @brief Destructor.
 * Releases dynamically allocated memory owned by the array.
 * Safe to call on NULL pointer (delete[] handles it).
 */
template<typename T>
Array<T>::~Array()
{
	LOG_DEBUG() << "Array destructor called";
	delete[] _array;
}

/*****************************************************************************
 *                            SUBSCRIPT OPERATOR                             *
 *****************************************************************************/

/**
 * @brief Subscript operator (non-const).
 * Provides mutable access to elements by index.
 * Performs bounds checking and throws std::out_of_range
 * if index is invalid.
 *
 * @param index Position of the element.
 * @return Reference to the element.
 */
template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return (_array[index]);
}

/**
 * @brief Subscript operator (const).
 * Provides read-only access to elements by index.
 * Performs bounds checking and throws std::out_of_range
 * if index is invalid.
 *
 * @param index Position of the element.
 * @return Const reference to the element.
 */
template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return (_array[index]);
}

/*****************************************************************************
 *                                ACCESSORS                                  *
 *****************************************************************************/

/**
 * @brief Returns the number of elements in the array.
 * @return Current array size.
 */
template<typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

/*****************************************************************************
 *                              STREAM OPERATORS                             *
 *****************************************************************************/

/**
 * @brief Stream insertion operator for Array.
 * Prints array contents in indexed format.
 * Displays a message if the array is empty.
 *
 * @param os Output stream.
 * @param a Array to print (passed by const reference).
 * @return Reference to the output stream.
 */
template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& a)
{
	if (a.size() == 0)
		os << "Array is empty (size: " << a.size() << ")\n";
	
	for (unsigned int i = 0; i < a.size(); i++)
	{
		os << "[" << i << "]" << " "
			<< a[i] << "\n";
	}
	return (os);
}
