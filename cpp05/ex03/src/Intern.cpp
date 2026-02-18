/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:58:49 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/18 10:02:16 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Logger.hpp"
#include <stdexcept>
#include <string>

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

/**
 * @brief Default constructor.
 * Logs creation of an Intern instance.
 */
Intern::Intern()
{
    LOG_DEBUG() << "Intern default constructor called";
}

/**
 * @brief Copy constructor.
 * Intern has no state to copy.
 * @param other Intern to copy from.
 */
Intern::Intern(const Intern& other)
{
    (void)other; // nothing to copy
    LOG_DEBUG() << "Intern copy constructor called";
}


/**
 * @brief Copy assignment operator.
 * Intern has no state to assign.
 * @param other Intern to assign from.
 * @return Reference to this Intern.
 */
Intern& Intern::operator=(const Intern& other)
{
    (void)other; // nothing to assign
    LOG_DEBUG() << "Intern copy assignment called";
    return *this;
}

Intern::~Intern()
{
    LOG_DEBUG() << "Intern destructor called";
}

/**
 * @brief Destructor.
 * Logs destruction of an Intern instance.
 */
/*****************************************************************************
 *                         STATIC BUILDER FUNCTIONS                          *
 *****************************************************************************/

/**
 * @brief Create a ShrubberyCreationForm.
 * @param target Target for the form.
 * @return New ShrubberyCreationForm instance.
 */
static AForm* createShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

/**
 * @brief Create a RobotomyRequestForm.
 * @param target Target for the form.
 * @return New RobotomyRequestForm instance.
 */
static AForm* createRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}


/**
 * @brief Create a PresidentialPardonForm.
 * @param target Target for the form.
 * @return New PresidentialPardonForm instance.
 */
static AForm* createPresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

/*****************************************************************************
 *                                 FORM TABLE                                *
 *****************************************************************************/

/**
 * @brief Entry mapping a form name to its builder function.
 */
struct FormEntry
{
	const char* name;
	function	formBuilder;
};


/**
 * @brief Static table of supported form types.
 */
static const FormEntry forms[] = {
	{ "shrubbery request", createShrubbery },
	{ "robotomy request" , createRobotomy },
	{ "presidential request", createPresidential }
};

/**
 * @brief Number of available form types.
 */
static const size_t TOTAL_FORMS = sizeof(forms) / sizeof(forms[0]);

/*****************************************************************************
 *                                  METHODS                                  *
 *****************************************************************************/

/**
 * @brief Create a form by name.
 * Searches the form table and calls the matching builder.
 *
 * @param formName Name of the requested form.
 * @param target Target for the form.
 * @return Pointer to created form.
 * @throw std::invalid_argument If name is not recognized.
 */
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	for(size_t i = 0; i < TOTAL_FORMS; i++)
	{
		if (formName == forms[i].name)
		{
			LOG_INFO() << "Intern creates " << formName;
			return (forms[i].formBuilder(target));
		}
	}
	throw std::invalid_argument("unrecognized form name: " + formName);
}
