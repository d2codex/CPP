/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:56:41 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 10:57:54 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

/**
 * @class Dog
 * @brief Derived class representing a dog animal.
 *
 * Implements dog-specific sound behavior and manages a Brain object
 * with ideas access.
 */
class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();
	
	std::string getIdeaAtIndex(size_t index) const;
	void setIdeaAtIndex(const std::string& idea, size_t index);
	void makeSound() const;

private:
	Brain* _brain;
};
