#include "RobotomyRequestForm.hpp"
#include "Logger.hpp"
#include <stdexcept>
#include <ctime>
#include <cstdlib>

/**
 * @brief Constructs a RobotomyRequestForm with a target.
 * Initializes required grades and validates the target string.
 */
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("Robotomy", 72, 45),
	_robotomy(target)
{
	if (_robotomy.empty())
		throw std::invalid_argument("Target cannot be empty");
	LOG_DEBUG() << "RobotomyRequestForm constructor called";
	LOG_DEBUG() << *this;
}

/**
 * @brief Constructs a copy of another RobotomyRequestForm.
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other),
	_robotomy(other._robotomy)
{
	LOG_DEBUG() << "RobotomyRequestForm copy constructor called";
	LOG_DEBUG() << *this;
}

/**
 * @brief Assigns another RobotomyRequestForm to this instance.
 */
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

/**
 * @brief Destroys the RobotomyRequestForm.
 */
RobotomyRequestForm::~RobotomyRequestForm()
{
	LOG_DEBUG() << "RobotomyRequestForm destructor called";
}

/**
 * @brief Returns the target of the robotomy form.
 */
const std::string	RobotomyRequestForm::getTarget() const
{
	return (_robotomy);
}

/**
 * @brief Attempts to robotomize the target.
 *
 * Outputs drilling noises and reports success or failure.
 */
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
