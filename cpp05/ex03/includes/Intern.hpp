#pragma once

#include "AForm.hpp"

typedef AForm* (*function)(const std::string&);

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target);
};
