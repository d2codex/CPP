/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:52:03 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/18 09:52:05 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

/**
 * @class ShrubberyCreationForm
 * @brief Creates a shrubbery file for a target.
 *
 * Writes ASCII trees to a file when executed successfully.
 */
class ShrubberyCreationForm : public AForm
{
public:
	explicit ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	//getter
	const std::string getTarget() const;
	
private:
	virtual void executeAction() const; 
	std::string	_shrubbery;
};
