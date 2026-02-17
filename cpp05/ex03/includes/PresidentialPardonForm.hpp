#pragma once

#include "AForm.hpp"

/**
 * @class PresidentialPardonForm
 * @brief Grants a presidential pardon to a target.
 *
 * Informs that the target has been pardoned when executed successfully.
 */
class PresidentialPardonForm : public AForm
{
public:
	explicit PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	//getter
	const std::string getTarget() const;

private:
	virtual void executeAction() const;
	std::string	_presidential;
};
