#include "RobotomyRequestForm.hpp"
#include "Logger.hpp"
#include <stdexcept>
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("Robotomy", 72, 45),
	_robotomy(target)
{
	if (_robotomy.empty())
		throw std::invalid_argument("Target cannot be empty");
	LOG_DEBUG() << "RobotomyRequestForm constructor called";
	LOG_DEBUG() << *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other),
	_robotomy(other._robotomy)
{
	LOG_DEBUG() << "RobotomyRequestForm copy constructor called";
	LOG_DEBUG() << *this;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_robotomy = other._robotomy;
	}
	else
		LOG_WARNING() << "RobotomyRequestForm self-assignment ignored";
	LOG_DEBUG() << *this;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	LOG_DEBUG() << "RobotomyRequestForm destructor called";
}

const std::string	RobotomyRequestForm::getTarget() const
{
	return (_robotomy);
}

void RobotomyRequestForm::executeAction() const
{
	static bool flip = std::time(NULL) & 1; // start with even/odd seconds
    flip = !flip;
	LOG_INFO() << "bzzzz-drrrr-bzzzz beep boop bop";
	if (flip == 1)
		LOG_INFO() << _robotomy << " successful!";
	else
		LOG_INFO() << _robotomy << " unccessful";
}
