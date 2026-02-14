#pragma once

#include <string>

class Bureaucrat;

/**
 * @class Form
 * @brief Represents a form with signing and execution grade requirements.
 *
 * Can be signed by a Bureaucrat if their grade is sufficient.
 * Throws exceptions if grades are out of bounds or already signed.
 */
class Form
{
public:
	Form();
	Form(const std::string name, int sign, int execute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	// nested exceptions
	class GradeTooHighException : public std::exception
	{ public: virtual const char* what() const throw(); };

	class GradeTooLowException : public std::exception
	{ public: virtual const char* what() const throw(); };

	class FormAlreadySigned : public std::exception
	{ public: virtual const char* what() const throw(); };

	// getters
	const std::string	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	// methods
	void	beSigned(const Bureaucrat& b);
	
private:
	const std::string	_formName;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
};

// free functions
std::ostream& operator<<(std::ostream os, const Form& f);
