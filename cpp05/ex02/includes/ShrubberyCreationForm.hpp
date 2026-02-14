#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
//	ShrubberyCreationForm(const std::string name, target);
//	ShrubberyCreationForm(const ShrubberyCreationForm& other);
//	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
	
private:
	virtual void executeAction() const; 
	
	const std::string	_target;
};
