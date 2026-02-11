/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:58:54 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 10:59:05 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

/**
 * @class Brain
 * @brief Represents a collection of ideas for an Animal.
 *
 * Provides access and modification of ideas stored in a fixed-size array.
 */
class Brain
{
public:
	enum { ARRAY_SIZE = 100 };

	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	std::string getIdeaAtIndex(size_t index) const;
	void setIdeaAtIndex(const std::string& idea, size_t index);

private:
	std::string _ideas[ARRAY_SIZE];
};
