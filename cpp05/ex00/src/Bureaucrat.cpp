#include "Bureaucrat.hpp"
#include "tests.hpp"
#include "Logger.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	_name(name),
	_grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException(); 
	if (_grade > 150)
		throw GradeTooLowException();
	if (_name.empty())
		throw std::invalid_argument("Bureaucrat name cannot be empty");

	LOG_INFO() << "Bureaucrat constructor called";
	LOG_DEBUG() << "name: " << _name << '\n'
				<< "grade: " << _grade;
}

Bureaucrat::~Bureaucrat()
{
	LOG_INFO() << "Bureaucrat destructor called";
}

//nested class memeber function implementations

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade too low");
}

// getters
const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade += 1;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
