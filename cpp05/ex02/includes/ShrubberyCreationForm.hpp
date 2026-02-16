#pragma once

#include "AForm.hpp"

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
