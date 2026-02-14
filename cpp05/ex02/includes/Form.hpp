#pragma once

#include <string>

class Bureaucrat;

class Aform
{
public:
	Aform();
	Aform(const std::string name, int sign, int execute);
	Aform(const Aform& other);
	Aform& operator=(const Aform& other);
	virtual ~Aform();

	// nested exceptions
	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException(const std::string& formName);
			virtual const char* what() const throw();
		private:
			const std::string	_msg;
	};

	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException(const std::string& formName);
			virtual const char* what() const throw();
		private:
			const std::string	_msg;
	};

	class GradeTooLowToSignException : public std::exception
	{ public: virtual const char* what() const throw(); };

	class FormAlreadySignedException : public std::exception
	{
		public:
			FormAlreadySignedException(const std::string& formName);
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
	virtual void	execute(const Bureaucrat& executor) const = 0;
	
private:
	const std::string	_formName;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	cosnt std::string	_msg;
};

// free functions
std::ostream& operator<<(std::ostream& os, const Aform& f);
