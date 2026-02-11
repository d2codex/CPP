/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:58:42 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 10:58:43 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

/**
 * @class Cat
 * @brief Derived class representing a cat animal.
 *
 * Implements cat-specific sound behavior and manages a Brain object
 * for ideas storage.
 */
class Cat : public Animal
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
