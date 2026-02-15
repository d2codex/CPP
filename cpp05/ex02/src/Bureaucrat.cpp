#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "tests.hpp"
#include "Logger.hpp"

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

/**
 * @brief Default constructor for Bureaucrat.
 * Initializes _name to "default" and _grade to 150.
 */
Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	LOG_DEBUG() << "Bureaucrat defaul constructor called";
	LOG_DEBUG() << _name << " grade: " << _grade;
}

/**
 * @brief Constructs a Bureaucrat with the given name and grade.
 * @param name The bureaucrat's name (cannot be empty).
 * @param grade The bureaucrat's grade (1 = highest, 150 = lowest).
 * @throws GradeTooHighException if grade < 1.
 * @throws GradeTooLowException if grade > 150.
 * @throws std::invalid_argument if name is empty.
 */
Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	_name(name),
	_grade(grade)
{
	if (name.empty())
		throw std::invalid_argument("Bureaucrat name cannot be empty");
	if (_grade < 1)
		throw GradeTooHighException(); 
	if (_grade > 150)
		throw GradeTooLowException();

	LOG_DEBUG() << "Bureaucrat constructor called";
	LOG_DEBUG() << _name << " grade: " << _grade;
}

/**
 * @brief Copy constructor.
 * @param other The Bureaucrat to copy.
 * Copies the grade. The name is const and initialized once.
 */
Bureaucrat::Bureaucrat(const Bureaucrat& other) :
    _name(other._name),
    _grade(other._grade)
{
    LOG_DEBUG() << "Bureaucrat copy constructor called";
    LOG_DEBUG() << _name << ", grade " << _grade;
}

/**
 * @brief Copy assignment operator.
 * @param other The Bureaucrat to assign from.
 * @return Reference to this Bureaucrat.
 * Only the grade is assigned. The name is const and cannot change.
 */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        _grade = other._grade;  // only grade can be assigned
        LOG_DEBUG() << "Bureaucrat copy assignment";
        LOG_DEBUG() << _name << " new grade " << _grade;
    }
    return *this;
}

/**
 * @brief Destructor for Bureaucrat.
 */
Bureaucrat::~Bureaucrat()
{ LOG_DEBUG() << "Bureaucrat destructor called"; }

/*****************************************************************************
 *                            NESTED EXCEPTIONS                              *
 *****************************************************************************/

/**
 * @brief Returns the exception message for GradeTooHighException.
 */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{ return ("Bureaucrat grade too high"); }

/**
 * @brief Returns the exception message for GradeTooLowException.
 */
const char* Bureaucrat::GradeTooLowException::what() const throw()
{ return ("Bureaucrat grade too low"); }

/*****************************************************************************
 *                                 GETTERS                                   *
 *****************************************************************************/

/**
 * @brief Returns the bureaucrat's name.
 */
const std::string& Bureaucrat::getName() const
{ return (_name); }

/**
 * @brief Returns the bureaucrat's grade.
 */
int	Bureaucrat::getGrade() const
{ return (_grade); }


/*****************************************************************************
 *                      INCREMENT / DECREMENT OPERATORS                      *
 *****************************************************************************/

/**
 * @brief Increments the bureaucrat's grade by 1.
 * @throws GradeTooHighException if grade becomes < 1.
 */
void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade -= 1;
	LOG_DEBUG() << _name << " grade: " << _grade;
}

/**
 * @brief Decrements the bureaucrat's grade by 1.
 * @throws GradeTooLowException if grade becomes > 150.
 */
void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade += 1;
	LOG_DEBUG() << _name << " grade: " << _grade;
}

/*****************************************************************************
 *                               OVERLOADS                                   *
 *****************************************************************************/

/**
 * @brief Stream insertion operator for Bureaucrat.
 * @param os The output stream.
 * @param b The Bureaucrat object to print.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}

/*****************************************************************************
 *                                 METHODS                                   *
 *****************************************************************************/

/**
 * @brief Attempts to sign the given AForm.
 * Calls AForm::beSigned. Prints success or failure message. 
 * Propagates any exceptions thrown by the form.
 * @param f The AForm to be signed.
 * @throws GradeTooLowException if this Bureaucrat's grade is too low.
 * @throws AFormAlreadySigned if the AForm is already signed.
 */
void	Bureaucrat::signForm(AForm& f) const
{
	f.beSigned(*this);
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	form.execute(*this);
}
