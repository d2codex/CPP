#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "Logger.hpp"

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

/**
 * @brief Default constructor for Form.
 * Initializes _formName to "default", _isSigned to false, and grades to 150.
 */
Form::Form() :
	_formName("default"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(150)
{
	LOG_INFO() << "Form constructor called";
	LOG_DEBUG() << "Form name: " << _formName << '\n'
			    << "        Is signed: " << _isSigned << '\n'
				<< "        Grade to sign: " << _gradeToSign << '\n'
				<< "        Grade to execute: " << _gradeToExecute;
}

/**
 * @brief Constructs a Form with a given name and grade requirements.
 * _isSigned is initialized to false. Throws GradeTooHigh/LowException
 * if grades are out of bounds (1–150).
 */
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

/**
 * @brief Copy constructor for Form.
 * Copies all members including const members from another Form.
 */
Form::Form(const Form& other) :
	_formName(other._formName),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
	LOG_INFO() << "Form copy constructor called";
	LOG_DEBUG() << "Form name: " << _formName << '\n'
			    << "        Is signed: " << _isSigned << '\n'
				<< "        Grade to sign: " << _gradeToSign << '\n'
				<< "        Grade to execute: " << _gradeToExecute;
}

/**
 * @brief Copy assignment operator for Form.
 * Only copies the mutable _isSigned member. Self-assignment ignored.
 */
Form& Form::operator=(const Form& other)
{
	if (this != & other)
	{
		_isSigned = other._isSigned;
	}
	else
		LOG_WARNING() << "Form self-assignment ignored";
	LOG_DEBUG() << "Form name: " << _formName << '\n'
			    << "        Is signed: " << _isSigned << '\n'
				<< "        Grade to sign: " << _gradeToSign << '\n'
				<< "        Grade to execute: " << _gradeToExecute;
	
	return (*this);
}

/**
 * @brief Destructor for Form.
 */
Form::~Form()
{ LOG_INFO() << "Form destructor called"; }

/*****************************************************************************
 *                            NESTED EXCEPTIONS                              *
 *****************************************************************************/

/**
 * @brief Returns the exception message for GradeTooHighException.
 */
const char* Form::GradeTooHighException::what() const throw()
{ return ("Form grade too high"); }

/**
 * @brief Returns the exception message for GradeTooLowException.
 */
const char* Form::GradeTooLowException::what() const throw()
{ return ("Form grade too low"); }

/**
 * @brief Returns the exception message for FormAlreadySigned.
 */
const char* Form::FormAlreadySigned::what() const throw()
{ return ("Form already signed"); }

/*****************************************************************************
 *                                 GETTERS                                   *
 *****************************************************************************/

/**
 * @brief Returns the form's name.
 */
const std::string	Form::getName() const
{ return (_formName); }

/**
 * @brief Returns whether the form is signed.
 */
bool	Form::getIsSigned() const
{ return (_isSigned); }

/**
 * @brief Returns the grade required to sign the form.
 */
int	Form::getGradeToSign() const
{ return (_gradeToSign); }

/**
 * @brief Returns the grade required to execute the form.
 */
int	Form::getGradeToExecute() const
{ return (_gradeToExecute); }

/*****************************************************************************
 *                                 METHODS                                   *
 *****************************************************************************/

/**
 * @brief Signs the form if the Bureaucrat has sufficient grade.
 * Throws FormAlreadySigned if already signed, or GradeTooLowException
 * if Bureaucrat grade is insufficient.
 */
void	Form::beSigned(const Bureaucrat& b)
{
	if (_isSigned == true)
		throw FormAlreadySigned();
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}
