#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Logger.hpp"
#include <sstream>

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

/**
 * @brief Default constructor for AForm.
 * Initializes _formName to "default", _isSigned to false, and grades to 150.
 */
AForm::AForm() :
	_formName("default"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(150)
{
	LOG_INFO() << "AForm constructor called";
	LOG_DEBUG() << _formName << '\n'
			    << "Is signed: " << _isSigned << '\n'
				<< "Grade to sign: " << _gradeToSign << '\n'
				<< "Grade to execute: " << _gradeToExecute;
}

/**
 * @brief Constructs a AForm with a given name and grade requirements.
 * _isSigned is initialized to false. Throws GradeTooHigh/LowException
 * if grades are out of bounds (1–150).
 */
AForm::AForm(const std::string formName, int sign, int execute) :
	_formName(formName),
	_isSigned(false),
	_gradeToSign(sign),
	_gradeToExecute(execute)
{
	if (formName.empty())
		throw std::invalid_argument("AForm name cannot be empty");
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException(_formName);
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException(_formName);
	LOG_INFO() << "AForm constructor called";
	LOG_DEBUG() << _formName << '\n'
			    << "Is signed: " << _isSigned << '\n'
				<< "Grade to sign: " << _gradeToSign << '\n'
				<< "Grade to execute: " << _gradeToExecute;
}

/**
 * @brief Copy constructor for AForm.
 * Copies all members including const members from another AForm.
 */
AForm::AForm(const AForm& other) :
	_formName(other._formName),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
	LOG_INFO() << "AForm copy constructor called";
	LOG_DEBUG() << _formName << '\n'
			    << "Is signed: " << _isSigned << '\n'
				<< "Grade to sign: " << _gradeToSign << '\n'
				<< "Grade to execute: " << _gradeToExecute;
}

/**
 * @brief Copy assignment operator for AForm.
 * Only copies the mutable _isSigned member. Self-assignment ignored.
 */
AForm& AForm::operator=(const AForm& other)
{
	if (this != & other)
	{
		_isSigned = other._isSigned;
	}
	else
		LOG_WARNING() << "AForm self-assignment ignored";
	LOG_DEBUG() << _formName << '\n'
			    << "Is signed: " << _isSigned << '\n'
				<< "Grade to sign: " << _gradeToSign << '\n'
				<< "Grade to execute: " << _gradeToExecute;
	
	return (*this);
}

/**
 * @brief Destructor for AForm.
 */
AForm::~AForm()
{ LOG_INFO() << "AForm destructor called"; }

/*****************************************************************************
 *                            NESTED EXCEPTIONS                              *
 *****************************************************************************/

AForm::GradeTooHighException::GradeTooHighException(const std::string& formName)
	: _msg(formName + " grade too high") {}

/**
 * @brief Returns the exception message for GradeTooHighException.
 */
const char* AForm::GradeTooHighException::what() const throw()
{ return (_msg.c_str()); }

AForm::GradeTooLowException::GradeTooLowException(const std::string& formName)
	: _msg(formName + " grade too low") {}

/**
 * @brief Returns the exception message for GradeTooLowException.
 */
const char* AForm::GradeTooLowException::what() const throw()
{ return (_msg.c_str()); }

/**
 * @brief Returns the exception message for GradeTooLowToSignException.
 */
const char* AForm::GradeTooLowToSignException::what() const throw()
{ return ("Bureaucrat grade too low to sign"); }

AForm::AlreadySignedException::AlreadySignedException(const std::string& formName)
	: _msg(formName + " already signed") {}

/**
 * @brief Returns the exception message for AFormAlreadySigned.
 */
const char* AForm::AlreadySignedException::what() const throw()
{ return (_msg.c_str()); }

/*****************************************************************************
 *                                 GETTERS                                   *
 *****************************************************************************/

/**
 * @brief Returns the form's name.
 */
const std::string	AForm::getName() const
{ return (_formName); }

/**
 * @brief Returns whether the form is signed.
 */
bool	AForm::getIsSigned() const
{ return (_isSigned); }

/**
 * @brief Returns the grade required to sign the form.
 */
int	AForm::getGradeToSign() const
{ return (_gradeToSign); }

/**
 * @brief Returns the grade required to execute the form.
 */
int	AForm::getGradeToExecute() const
{ return (_gradeToExecute); }

/*****************************************************************************
 *                                 METHODS                                   *
 *****************************************************************************/

/**
 * @brief Signs the form if the Bureaucrat has sufficient grade.
 * Throws AFormAlreadySigned if already signed, or GradeTooLowException
 * if Bureaucrat grade is insufficient.
 */
void	AForm::beSigned(const Bureaucrat& b)
{
	if (_isSigned == true)
		throw AlreadySignedException(_formName);
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowToSignException();
}

/*****************************************************************************
 *                                OVERLOAD                                   *
 *****************************************************************************/

/**
 * @brief Outputs the AForm state to an output stream.
 *
 * Prints the form name, signed status, and required grades.
 *
 * @param os Output stream.
 * @param f AForm to display.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm: " << f.getName() << '\n';

	if (f.getIsSigned() == true)
		os << "Signed: yes" << '\n';
	else
		os << "Signed: no" << '\n';
	os << "Grade required to sign: " << f.getGradeToSign() << '\n';
	os << "Grade required to execute: " << f.getGradeToExecute();
	return (os);
}
