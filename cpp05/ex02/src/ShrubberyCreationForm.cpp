#include "ShrubberyCreationForm.hpp"
#include "Logger.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("Shrubbery", 145, 137),
	_shrubbery(target)
{
	if (_shrubbery.empty())
		throw std::invalid_argument("Target cannot be empty");
	LOG_DEBUG() << "ShrubberyCreationForm constructor called";
	LOG_DEBUG() << *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other),
	_shrubbery(other._shrubbery)
{
	LOG_DEBUG() << "ShrubberyCreationForm copy constructor called";
	LOG_DEBUG() << *this;
}

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

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	LOG_DEBUG() << "ShrubberyCreationForm destructor called";
}

const std::string ShrubberyCreationForm::getTarget() const
{
	return (_shrubbery);
}

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

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_shrubbery + "Shrubbery.txt").c_str());

	if (!file)
		throw std::runtime_error("File open error");

	printTree(file);
	
	if (file.fail())
	    throw std::runtime_error("File write error");
	file.close();
}
