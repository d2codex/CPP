#include "PresidentialPardonForm.hpp"
#include "Logger.hpp"
#include <stdexcept>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("Presidential", 25, 5),
	_presidential(target)
{
	if (_presidential.empty())
		throw std::invalid_argument("Target cannot be empty");
	LOG_DEBUG() << "PresidentialPardonForm constructor called";
	LOG_DEBUG() << *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other),
	_presidential(other._presidential)
{
	LOG_DEBUG() << "PresidentialPardonForm copy constructor called";
	LOG_DEBUG() << *this;
}

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

PresidentialPardonForm::~PresidentialPardonForm()
{
	LOG_DEBUG() << "PresidentialPardonForm destructor called";
}

const std::string	PresidentialPardonForm::getTarget() const
{
	return (_presidential);
}

void PresidentialPardonForm::executeAction() const
{
	LOG_INFO() << _presidential << " has been pardoned by Zaphod Beeblebrox";
}
