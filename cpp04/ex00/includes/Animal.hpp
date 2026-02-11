/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:36:35 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 10:41:30 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

/**
 * @class Animal
 * @brief Base class representing a generic animal.
 * Provides a common interface for derived animal types,
 * including type handling and polymorphic sound behavior.
 */
class Animal
{
public:
	Animal();
	Animal(const std::string& type);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	// without virtual a derived class would call parent destructor
	// and not the herited class destructor causing leaks
	virtual ~Animal();

	const std::string getType() const;
	// virtual allows for inherited classes to call the most
	// derived function instead of base class function
	virtual void makeSound() const;

protected:
	std::string	_type;
};
