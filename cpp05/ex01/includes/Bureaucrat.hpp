#pragma once

#include <string>
#include <stdexcept>

class Form;

/**
 * @class Bureaucrat
 * @brief Represents a bureaucrat with a name and a grade.
 *
 * A Bureaucrat has a constant name and a grade in the range 1-150.
 * The grade can be incremented or decremented. Out-of-range grades
 * throw GradeTooHighException or GradeTooLowException. Provides getters
 * for name and grade, and nested exception classes for invalid grades.
 */
class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	// nested exception classes
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

	// getters
	const std::string&	getName() const;
	int					getGrade() const;

	// increment / decrement
	void	incrementGrade();
	void	decrementGrade();

	void	signForm(Form& f) const;
	
private:
	const std::string	_name;
	int					_grade;
};

// free functions
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
