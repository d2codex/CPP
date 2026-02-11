/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:08:25 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 11:08:40 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

/**
 * @class Dog
 * @brief Derived class representing a dog animal.
 *
 * Implements dog-specific sound behavior and manages a Brain object
 * for storing and accessing ideas.
 */
class Dog : public AAnimal
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
