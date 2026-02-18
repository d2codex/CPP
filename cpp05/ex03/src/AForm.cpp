/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:58:42 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/18 09:58:43 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	LOG_DEBUG() << "AForm default constructor called";
	LOG_DEBUG() << *this;
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
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	LOG_DEBUG() << "AForm constructor called";
	LOG_DEBUG() << *this;
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
	LOG_DEBUG() << "AForm copy constructor called";
	LOG_DEBUG() << *this;
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
	LOG_DEBUG() << *this;
	
	return (*this);
}

/**
 * @brief Destructor for AForm.
 */
AForm::~AForm()
{
	LOG_DEBUG() << "AForm destructor called";
}

/*****************************************************************************
 *                            NESTED EXCEPTIONS                              *
 *****************************************************************************/

/**
 * @brief Returns the exception message for GradeTooHighException.
 */
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("form grade too high");
}

/**
 * @brief Returns the exception message for GradeTooLowException.
 */
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("form grade too low");
}

/**
 * @brief Constructs a GradeTooLowToSignException with a message.
 */
AForm::GradeTooLowToSignException::GradeTooLowToSignException(const std::string& msg) :
	_msg(msg)
{
	LOG_DEBUG() << "GradeTooLowToSignException constructor called";
}

/**
 * @brief Returns the exception message for GradeTooLowToSignException.
 */
const char* AForm::GradeTooLowToSignException::what() const throw()
{
	return (_msg.c_str());
}

/**
 * @brief Destroys the GradeTooLowToSignException.
 */
AForm::GradeTooLowToSignException::~GradeTooLowToSignException() throw()
{
	LOG_DEBUG() << "GradeTooLowToSignException destructor called";
}

/**
 * @brief Constructs an AlreadySignedException with a message.
 */
AForm::AlreadySignedException::AlreadySignedException(const std::string& msg) :
	_msg(msg)
{
	LOG_DEBUG() << "AlreadySignedException constructor called";
}

/**
 * @brief Destroys the AlreadySignedException.
 */
AForm::AlreadySignedException::~AlreadySignedException() throw()
{
	LOG_DEBUG() << "AlreadySignedException destructor called";
}

/**
 * @brief Returns the exception message for AFormAlreadySigned.
 */
const char* AForm::AlreadySignedException::what() const throw()
{
	return (_msg.c_str());
}

/**
 * @brief Constructs a FormNotSignedException with a message.
 */
AForm::FormNotSignedException::FormNotSignedException(const std::string& msg)
	: _msg(msg)
{
	LOG_DEBUG() << "FormNotSignedException constructor called";
}

/**
 * @brief Destroys the FormNotSignedException.
 */
AForm::FormNotSignedException::~FormNotSignedException() throw()
{
	LOG_DEBUG() << "FormNotSignedException destructor called";
}

/**
 * @brief Returns the exception message for FormNotSignedException.
 */
const char* AForm::FormNotSignedException::what() const throw()
{
	return (_msg.c_str());
}

/*****************************************************************************
 *                                 GETTERS                                   *
 *****************************************************************************/

/**
 * @brief Returns the form's name.
 */
const std::string	AForm::getName() const
{
	return (_formName);
}

/**
 * @brief Returns whether the form is signed.
 */
bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

/**
 * @brief Returns the grade required to sign the form.
 */
int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

/**
 * @brief Returns the grade required to execute the form.
 */
int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

/*****************************************************************************
 *                                OVERLOAD                                   *
 *****************************************************************************/

/**
 * @brief Outputs the AForm state to an output stream.
 * Prints the form name, signed status, and required grades.
 * @param os Output stream.
 * @param f AForm to display.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "Form: " << f.getName() << '\n';

	if (f.getIsSigned() == true)
		os << "Signed: yes" << '\n';
	else
		os << "Signed: no" << '\n';
	os << "Grade required to sign: " << f.getGradeToSign() << '\n';
	os << "Grade required to execute: " << f.getGradeToExecute();
	return (os);
}

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
	{
		const std::string	msgSigned =
			b.getName() + " could not sign " + _formName +
			" form (already signed)";
		throw AlreadySignedException(msgSigned);
	}
	if (b.getGrade() <= _gradeToSign)
	{
		_isSigned = true;
		LOG_INFO() << b.getName() << " signed " << _formName << " form";
	}
	else
	{
		const std::string	msgGrade =
			b.getName() + " could not sign " + _formName +
			" because grade too low";
		throw GradeTooLowToSignException(msgGrade);
	}
}

/**
 * @brief Executes the form if signed and executor grade is sufficient.
 * Throws if the form is not signed or if the executor grade is too low.
 */
void	AForm::execute(const Bureaucrat& executor) const
{
		if (_isSigned == false)
		{
			const std::string msgNotSigned =
				executor.getName() + " could not execute " + _formName +
				" because form not signed";
			throw AForm::FormNotSignedException(msgNotSigned);
		}
		if (executor.getGrade() <= _gradeToExecute)
		{
			executeAction();
			LOG_INFO() << executor.getName() << " executed form "
					  << _formName;
		}
		else
		{
			const std::string msgExecute =
				executor.getName() + " could not execute " + _formName +
				"because grade too low";
			throw AForm::GradeTooLowToSignException(msgExecute);
		}
}
