/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:08:00 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 11:08:11 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

/**
 * @class Cat
 * @brief Derived class representing a cat animal.
 *
 * Implements cat-specific sound behavior and manages a Brain object
 * for storing and accessing ideas.
 */
class Cat : public AAnimal
{
public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	std::string getIdeaAtIndex(size_t index) const;
	void setIdeaAtIndex(const std::string& idea, size_t index);

	void makeSound() const;

private:
	Brain* _brain;
};
