/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:59:36 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 10:59:38 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

/**
 * @class Animal
 * @brief Base class representing a generic animal.
 *
 * Provides common behavior and a polymorphic interface for derived animals.
 */
class Animal
{
public:
	Animal();
	Animal(const std::string& type);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	const std::string getType() const;
	virtual void makeSound() const;

protected:
	std::string	_type;
};
