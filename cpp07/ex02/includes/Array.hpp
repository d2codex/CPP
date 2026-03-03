#pragma once

#include "Logger.hpp"
#include <stddef>

//TODO add in README why I chose hybrid template - declare class,
//but define outside of class and in the same file
//good for small to medium projects - better readability, all in one place
// more user friendly only .hpp to remeber to add
//cons less flexible than with separate .tpp, slower compilation
// no control over instantiation - all code is availabe to user so any
// type can be instantiated.

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

template<typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
	LOG_DEBUG() << "Array default constructor called";
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
	LOG_DEBUG() << "Array parameter constructor called";
	LOG_DEBUG() << "Array size: " << _size;
}

// TODO add to README: don't use operator= to copy (*this = other)
// since _array and _size could be uninitialized before operator=
// runs since it calls delete[] on an unitialized pointer causing
// undefined behavior
template<typename T>
Array<T>::Array(Array& other) : _array(new T[other._size], _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
	LOG_DEBUG() << "Array Copy constructor called";
	LOG_DEBUG() << "Array size: " << _size;
}

// TODO: add this explanation to README
// check _size > 0 so we dont allocate an empty array? - design choice
// do i allow it?  yes allow empty array, it can be reassigned later so
// don't check for it.
template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T* new_array = new T[other._size]; // allocate first before deleteing _array
										   // if it fails there wont be a dangling ptr.
		for (unsigned int i = 0; i < other._size; i++)
			new_array[i] = other._array[i]; // deep copy
											//
		delete[] _array; // only delete old array after successful
		_array = new_array;
		_size = other._size;

		LOG_DEBUG() << "Array assignment operator called";
		LOG_DEBUG() << "Array size: " << _size;
	}
	else
		LOG_DEBUG() << "Self-assignment ignored";
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	LOG_DEBUG() << "Array destructor called";
	delete[] _array
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return (_array[index]);
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return (_array[index]);
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}
