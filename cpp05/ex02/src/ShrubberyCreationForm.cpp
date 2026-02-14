#include "ShrubberyCreationForm.hpp"
#include "Logger.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery", 145, 137)
{
	LOG_INFO() << "ShrubberyCreationForm constructor called";
	LOG_DEBUG() << this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{ LOG_INFO() << "ShrubberyCreationForm destructor called"; }

void ShrubberyCreationForm::executeAction() const
{
	// actual shrubbery logic here
}
