#pragma once

#include "AForm.hpp"

/**
 * @class RobotomyRequestForm
 * @brief Attempts to robotomize a target.
 *
 * Produces drilling noises and reports success or failure when executed.
 */
class RobotomyRequestForm : public AForm
{
public:
	explicit RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	//getter
	const std::string getTarget() const;

private:
	virtual void executeAction() const;
	std::string	_robotomy;
};
