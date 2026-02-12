#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "Logger.hpp"
#include <iomanip>

Form::Form(const std::string formName, int sign, int execute) :
	_formName(formName),
	_isSigned(false),
	_gradeToSign(sign),
	_gradeToExecute(execute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	LOG_INFO() << "Form constructor called";
	LOG_DEBUG() << "Form name: " << _formName << '\n'
			    << "        Is signed: " << _isSigned << '\n'
				<< "        Grade to sign: " << _gradeToSign << '\n'
				<< "        Grade to execute: " << _gradeToExecute;
}

Form::~Form()
{
	LOG_INFO() << "For destructor called";
}

// nested exceptions
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}

const std::string	Form::getName() const
{
	return (_formName);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}
