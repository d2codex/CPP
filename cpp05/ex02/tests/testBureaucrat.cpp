/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testBureaucrat.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 22:14:23 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/15 23:32:57 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "tests.hpp"
#include "Logger.hpp"
#include <sstream>

class TestForm : public AForm
{
public:
	TestForm(const std::string& target) :
		AForm("TestForm", 145, 137),
		_target(target) {}
	virtual ~TestForm() {}

protected:
	void executeAction() const 
	{ std::cout << "TestForm action executed\n"; }

private:
	std::string	_target;
};


int	testBureaucrat()
{
	printHeader("Bureaucrat Class");
	int	failed = 0;
	int	total = 0;

	// Class test: Exception too high returns correct message
	{
		std::exception* e = new Bureaucrat::GradeTooHighException();
		const char* expected = "Bureaucrat grade too high";

		total++;
		if (!assertEqual("exception too high returns correct message",
						 expected, e->what()))
			failed++;
		delete e;
	}
	// Class test: Exception too low returns correct message
	{
		std::exception* e = new Bureaucrat::GradeTooLowException();
		const char* expected = "Bureaucrat grade too low";

		total++;
		if (!assertEqual("exception too low returns correct message",
						 expected, e->what()))
			failed++;
		delete e;
	}
	// test default constructor name and grade
	{
		Bureaucrat a;

		total++;
		if (!assertEqual("default ctor name matches", "default", a.getName()))
			failed++;

		total++;
		if (!assertEqual("default ctor grade matches", 150, a.getGrade()))
			failed++;
	}
	// object: grade too high - out of range
	{
		try
		{
			Bureaucrat("plankton", 0);
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			const char* expected = "Bureaucrat grade too high";

			total++;
			if (!assertEqual("grade too high - out of range", expected, e.what()))
				failed++;
		}
	}
	// object: grade too low - out of range
	{
		try
		{
			Bureaucrat("plankton", 151);
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			const char* expected = "Bureaucrat grade too low";

			total++;
			if (!assertEqual("grade too low - out of range", expected, e.what()))
				failed++;
		}
	}
	// getGrade normal valid value
	{
		Bureaucrat a("plankton", 70);

		total++;
		if (!assertEqual("getGrade normal valid value", 70, a.getGrade()))
			failed++;
	}
	// getName valid name
	{
		Bureaucrat a("plankton", 70);
		
		total++;
		if (!assertEqual("getName valid name", "plankton", a.getName()))
			failed++;
	}
	// getName invalid empty name
	{
		try
		{
			Bureaucrat a("", 100);
		}
		catch (std::exception& e)
		{
			const char* expected = "Bureaucrat name cannot be empty";
			if (!assertEqual("getName invalid empty name", expected, e.what()))
				failed++;
		}
	}
	// increment valid normal value
	{
		Bureaucrat a("plankton", 70);
		a.incrementGrade();	
		total++;
		if (!assertEqual("incrementGrade - valid normal value", 69, a.getGrade()))
			failed++;
	}
	// increment edge case - grade at max value
	{
		try
		{
			Bureaucrat a("plankton", 1);
			a.incrementGrade();	
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			const char* expected = "Bureaucrat grade too high";
			total++;
			if (!assertEqual("incrementGrade - invalid grade at max value",
							 expected, e.what()))
				failed++;
		}
	}
	// decrement valid normal value
	{
		Bureaucrat a("plankton", 70);
		a.decrementGrade();
		total++;
		if (!assertEqual("decrementGrade - valid normal value", 71, a.getGrade()))
			failed++;
	}
	// decrement edge case - grade at min value
	{
		try
		{
			Bureaucrat a("plankton", 150);
			a.decrementGrade();
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			const char* expected = "Bureaucrat grade too low";
			total++;
			if (!assertEqual("decrementGrade - invalid grade at min value",
							 expected, e.what()))
				failed++;
		}
	}
	// operator overload
	{
		Bureaucrat a("spongebob", 32);

		std::ostringstream oss;
		oss << a;
		std::string expected = "spongebob, bureaucrat grade 32";
		
		total++;
		if (!assertEqual("operator overload prints correct message",
						 expected, oss.str()))
			failed++;
	}
	// Copy constructor
	{
		Bureaucrat original("Sandy", 42);
		Bureaucrat copy(original);

		total++;
		if (!assertEqual("copy constructor copies grade", original.getGrade(),
					copy.getGrade()))
			failed++;
		total++;
		if (!assertEqual("copy constructor copies name", original.getName(),
					copy.getName()))
			failed++;
	}
	// assignment opeartor
	{
		Bureaucrat a("Patrick", 100);
		Bureaucrat b("Squidward", 50);

		b = a; // assign Patrick to Squidward

		total++;
		if (!assertEqual("copy assignment copies grade", a.getGrade(),
					b.getGrade()))
			failed++;
		total++;
		if (!assertEqual("copy assignment keeps original name",
					std::string("Squidward"), b.getName()))
			failed++;
	}
	// test SignForm
	{
		TestForm tf("TestForm");
		Bureaucrat bob("Bob", 25);
		total++;

		bob.signForm(tf);
		if (!assertEqual("signForm success", true, tf.getIsSigned()))
			failed++;
	}
	// test SignForm fail
	{
		try
		{
			TestForm tf("TestForm");
			Bureaucrat bob("Bob", 150);
			bob.signForm(tf);
		}
		catch (std::exception& e)
		{
			const std::string expected =
				"Bob could not sign TestForm because grade too low";

			total++;
			if (!assertEqual("signForm fail", expected, e.what()))
				failed++;
		}
	}
	printSummary(failed, total);
	return (failed);
}
