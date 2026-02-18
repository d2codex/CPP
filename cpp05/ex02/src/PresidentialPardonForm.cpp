/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:50:19 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/18 10:52:13 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Logger.hpp"
#include <stdexcept>

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

/**
 * @brief Constructs a PresidentialPardonForm with a target.
 * Initializes required grades and validates the target string.
 */
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("Presidential", 25, 5),
	_presidential(target)
{
	if (_presidential.empty())
		throw std::invalid_argument("Target cannot be empty");
	LOG_DEBUG() << "PresidentialPardonForm constructor called";
	LOG_DEBUG() << *this;
}

/**
 * @brief Constructs a copy of another PresidentialPardonForm.
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other),
	_presidential(other._presidential)
{
	LOG_DEBUG() << "PresidentialPardonForm copy constructor called";
	LOG_DEBUG() << *this;
}

/**
 * @brief Assigns another PresidentialPardonForm to this instance.
 */
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_presidential = other._presidential;
	}
	else
		LOG_WARNING() << "PresidentialPardonForm self-assignment ignored";
	LOG_DEBUG() << *this;
	return (*this);
}

/**
 * @brief Destroys the PresidentialPardonForm.
 */
PresidentialPardonForm::~PresidentialPardonForm()
{
	LOG_DEBUG() << "PresidentialPardonForm destructor called";
}

/*****************************************************************************
 *                                 GETTERS                                   *
 *****************************************************************************/

/**
 * @brief Returns the target of the pardon form.
 */
const std::string	PresidentialPardonForm::getTarget() const
{
	return (_presidential);
}

/*****************************************************************************
 *                                 METHODS                                   *
 *****************************************************************************/

/**
 * @brief Announces the presidential pardon of the target.
 */
void PresidentialPardonForm::executeAction() const
{
	LOG_INFO() << _presidential << " has been pardoned by Zaphod Beeblebrox";
}
