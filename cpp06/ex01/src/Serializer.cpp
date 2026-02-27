/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 01:11:40 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/27 01:11:42 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Logger.hpp"

/**
 * @brief Default constructor (private to prevent instantiation).
 */
Serializer::Serializer() {}

/**
 * @brief Copy assignment operator (private to prevent assignment).
 * @return Reference to this Serializer (unused).
 */
Serializer::Serializer(const Serializer&) {}


/**
 * @brief Copy assignment operator (private to prevent assignment).
 * @return Reference to this Serializer (unused).
 */
Serializer& Serializer::operator=(const Serializer&)
{ return (*this); }

/**
 * @brief Destructor (private, does nothing).
 */
Serializer::~Serializer() {}

/**
 * @brief Converts a Data pointer into a uintptr_t for serialization.
 * @param ptr Pointer to a Data object to serialize.
 * @return Serialized pointer as uintptr_t.
 */
uintptr_t	Serializer::serialize(Data* ptr)
{
	LOG_DEBUG() << "original ptr: " << ptr;
	return (reinterpret_cast<uintptr_t>(ptr));
}

/**
 * @brief Converts a uintptr_t back into a Data pointer.
 * @param raw Serialized pointer as uintptr_t.
 * @return Deserialized Data pointer.
 */
Data*	Serializer::deserialize(uintptr_t raw)
{
	LOG_DEBUG() << "raw value: " << raw;
	LOG_DEBUG() << "raw value hex: 0x" << std::hex << raw;
	return(reinterpret_cast<Data*>(raw));
}
