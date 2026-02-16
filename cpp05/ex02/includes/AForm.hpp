#pragma once

#include <string>

class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(const std::string name, int sign, int execute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

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

	class GradeTooLowToSignException : public std::exception
	{
		public:
			GradeTooLowToSignException(const std::string& msg);
			~GradeTooLowToSignException() throw();
			virtual const char* what() const throw();
		private:
			const std::string	_msg;
	};

	class AlreadySignedException : public std::exception
	{
		public:
			AlreadySignedException(const std::string& msg);
			~AlreadySignedException() throw();
			virtual const char* what() const throw();
		private:
			const std::string	_msg;
	};

	class FormNotSignedException : public std::exception
	{
		public:
			FormNotSignedException(const std::string& msg);
			~FormNotSignedException() throw();
			virtual const char* what() const throw();
		private:
			const std::string	_msg;
	};

	// getters
	const std::string	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	// methods
	void	beSigned(const Bureaucrat& b);

	// make form abstract
	virtual void	execute(const Bureaucrat& executor) const;

protected:
	virtual void	executeAction() const = 0;

private:
	const std::string	_formName;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
};

// free functions
std::ostream& operator<<(std::ostream& os, const AForm& f);
