#pragma once

#include <string>
#include <stdexcept>

class Bureaucrat
{
public:
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
	
private:
	const std::string	_name;
	int					_grade;
};

// free functions
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
