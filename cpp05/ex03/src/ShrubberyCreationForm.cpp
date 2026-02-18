/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:05:12 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/18 10:11:16 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Logger.hpp"
#include <fstream>
#include <stdexcept>

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

/**
 * @brief Constructs a ShrubberyCreationForm with a target.
 * Initializes required grades and validates the target string.
 */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("Shrubbery", 145, 137),
	_shrubbery(target)
{
	if (_shrubbery.empty())
		throw std::invalid_argument("Target cannot be empty");
	LOG_DEBUG() << "ShrubberyCreationForm constructor called";
	LOG_DEBUG() << *this;
}

/**
 * @brief Constructs a copy of another ShrubberyCreationForm.
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other),
	_shrubbery(other._shrubbery)
{
	LOG_DEBUG() << "ShrubberyCreationForm copy constructor called";
	LOG_DEBUG() << *this;
}

/**
 * @brief Assigns another ShrubberyCreationForm to this instance.
 */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_shrubbery = other._shrubbery;
	}
	else
		LOG_WARNING() << "ShrubberyCreationForm self-assignment ignored";
	LOG_DEBUG() << *this;
	return (*this);
}

/**
 * @brief Destroys the ShrubberyCreationForm.
 */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	LOG_DEBUG() << "ShrubberyCreationForm destructor called";
}

/*****************************************************************************
 *                                 GETTERS                                   *
 *****************************************************************************/

/**
 * @brief Returns the target of the shrubbery form.
 */
const std::string ShrubberyCreationForm::getTarget() const
{
	return (_shrubbery);
}

/*****************************************************************************
 *                                 METHODS                                   *
 *****************************************************************************/

/**
 * @brief Writes an ASCII shrubbery tree to the given file stream.
 */
static void printTree(std::ofstream& file)
{
	file << "                                       ..-%+:.:.\n";
	file << "                                   ...-%+:.:..%+:.\n";
	file << "                                   ....-%+:.-%+:.\n";
	file << "                                  ...-%.-%+:.:.+:.:.\n";
	file << "                                  .-%+:..-%+:.%.-%+:.\n";
	file << "                                      ||.-%+:.-%+:.\n";
	file << "                                      ||%+:.:.+:.\n";
	file << "                                      ||.-.-%+:.\n";
	file << "                                      .||+:.-%+:.\n";
	file << "                                      |/~\n";
	file << "                                      ||\n";
	file << "                                      ||\n";
	file << "                                      |/~\n";
	file << "                          .-%+:..-%+:./~|\n";
	file << "                          .-..-%+:.-%+|/\n";
	file << "                          .-%+:.%+:.+:/||\n";
	file << "                      .-%+:.%+:.-%+:.  ||\n";
	file << "                      .-%+:.+:.      _||\n";
	file << "                      .-%+:.+:.      /||\n";
	file << "                                      |/\n";
	file << "                                      /||\n";
	file << "                                      /||\n";
	file << "                                      /||\n";
	file << "                                      ||            _/\n";
	file << "                                      ||   _/_/_/  /_/_/\n";
	file << "                                      |/__/    / _/   / ..-%+.-%+:.\n";
	file << "                                      /~                /  .-%.-%+:..:.\n";
	file << "                                      |/                 /...%.-%+:..:.%+:.\n";
	file << "                                      /||                 /|.-.-%+:.-%+:.\n";
	file << "        .-%+:.-%+:.                  /~                   _/ .-.-%+:.\n";
	file << "       .-%.-..-%+:.:.                /~\n";
	file << "        .-.-%+:...:.                  /~|\n";
	file << "         .-%+:...%+:._|           ``____`/~/\n";
	file << "         .-%+:..%+:. /       ``___``     `/~\n";
	file << "        .-%+:.       ``__``__``_  ``__       /~/~\n";
	file << "                           :___________./~~~`.__________:\n";
	file << "                           ``                           /\n";
	file << "                            ``_________________________/\n";
	file << "                             (_)                     (_)\n";

}

/**
 * @brief Creates a shrubbery file and writes ASCII trees into it.
 * Throws if the file cannot be opened or written to.
 */
void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_shrubbery + "Shrubbery.txt").c_str());

	if (!file)
		throw std::runtime_error("File open error");

	printTree(file);
	
	if (file.fail())
	    throw std::runtime_error("File write error");
}
