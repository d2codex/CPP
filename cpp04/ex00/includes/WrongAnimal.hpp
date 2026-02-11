/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:37:12 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 10:42:30 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

/**
 * @class WrongAnimal
 * @brief Base class with incorrect polymorphic behavior.
 *
 * Lacks virtual functions to demonstrate inheritance issues.
 */
class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const std::string& type);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();

	const std::string getType() const;
	void makeSound() const;

protected:
	std::string _type;
};
