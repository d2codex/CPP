#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "tests.hpp"
#include "Logger.hpp"
#include <sstream>

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
	// Copy assignment
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
		Form tax("W-2", 30, 120);
		Bureaucrat bob("Bob", 25);

		total++;

		std::ostringstream oss;
		std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf()); // redirect cout
		bob.signForm(tax);
		std::cout.rdbuf(oldCout); // restore cout
		if (!assertEqual("signForm success", "Bob signed W-2\n", oss.str()))
			failed++;
	}
	// test SignForm fail
	{
		Form tax("W-2", 30, 120);
		Bureaucrat bob("Bob", 45);

		total++;

		const std::string expected = "Bob couldn't sign W-2 because Form grade too low\n";
		std::ostringstream oss;
		std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf()); // redirect cout
		bob.signForm(tax);
		std::cout.rdbuf(oldCout); // restore cout
		if (!assertEqual("signForm fail", expected, oss.str()))
			failed++;
	}
	printSummary(failed, total);
	return (failed);
}
