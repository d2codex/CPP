#pragma once

#include <string>

class Bureaucrat;

class Form
{
public:
	Form(const std::string name, int sign, int execute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	// nested exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class FormAlreadySigned : public std::exception
	{
		virtual const char* what() const throw();
	};

	const std::string	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	void	beSigned(const Bureaucrat& b);
	
private:
	const std::string	_formName;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
};

std::ostream& operator<<(std::ostream os, const Form& f);
