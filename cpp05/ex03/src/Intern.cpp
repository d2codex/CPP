#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Logger.hpp"
#include <stdexcept>
#include <string>

// constructors
Intern::Intern()
{
    LOG_DEBUG() << "Intern default constructor called";
}

Intern::Intern(const Intern& other)
{
    (void)other; // nothing to copy
    LOG_DEBUG() << "Intern copy constructor called";
}

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

// static builder functions

static AForm* createShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm* createRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* createPresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

// form table
struct FormEntry
{
	const char* name;
	function	formBuilder;
};

static const FormEntry forms[] = {
	{ "shrubbery request", createShrubbery },
	{ "robotomy request" , createRobotomy },
	{ "presidential request", createPresidential }
};

static const size_t TOTAL_FORMS = sizeof(forms) / sizeof(forms[0]);

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
	throw std::invalid_argument("unrecognized form name" + formName);
}
