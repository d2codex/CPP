/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:07:27 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 11:07:32 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

/**
 * @class AAnimal
 * @brief Abstract base class representing a generic animal.
 *
 * Provides a common interface for derived animals and enforces
 * polymorphic behavior via a pure virtual makeSound() function.
 */
class AAnimal
{
public:
	AAnimal(); // dont need
	AAnimal(const std::string& type); // cat and dog need this
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal();

	const std::string getType() const;
	// to make animal uninstantiable make at least one function virtual
	// add '= 0'
	virtual void makeSound() const = 0;

protected:
	std::string	_type;
};
