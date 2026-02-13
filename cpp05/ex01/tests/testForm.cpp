#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "tests.hpp"
#include "Logger.hpp"

int	testForm()
{
	printHeader("Form Class");
	int	failed = 0;
	int	total = 0;

	// Class test: Exception too high returns correct message
	{
		std::exception* e = new Form::GradeTooHighException();
		const char* expected = "Form grade too high";

		total++;
		if (!assertEqual("exception too high returns correct message",
						 expected, e->what()))
			failed++;
		delete e;
	}
	// Class test: Exception too low returns correct message
	{
		std::exception* e = new Form::GradeTooLowException();
		const char* expected = "Form grade too low";

		total++;
		if (!assertEqual("exception too low returns correct message",
						 expected, e->what()))
			failed++;
		delete e;
	}
	// object: sign too high - out of range
	{
		try { Form("plankton", 0, 5); }
		catch (Form::GradeTooHighException& e)
		{
			const char* expected = "Form grade too high";

			total++;
			if (!assertEqual("sign grade too high - out of range", expected, e.what()))
failed++;
		}
	}
	// object: execute too high - out of range
	{
		try { Form("plankton", 5, 0); }
		catch (Form::GradeTooHighException& e)
		{
			const char* expected = "Form grade too high";

			total++;
			if (!assertEqual("expect grade too high - out of range", expected, e.what()))
				failed++;
		}
	}
	// object: sign too low - out of range
	{
		try { Form("plankton", 151, 5); }
		catch (Form::GradeTooLowException& e)
		{
			const char* expected = "Form grade too low";

			total++;
			if (!assertEqual("sign grade too low - out of range", expected, e.what()))
				failed++;
		}
	}
	// object: execute too low - out of range
	{
		try { Form("plankton", 5, 151); }
		catch (Form::GradeTooLowException& e)
		{
			const char* expected = "Form grade too low";

			total++;
			if (!assertEqual("execute grade too low - out of range", expected, e.what()))
				failed++;
		}
	}
	// getName
	{
		Form a("plankton", 70, 71);

		total++;
		if (!assertEqual("getName", "plankton", a.getName()))
			failed++;
	}
	// getIsSigned false
	{
		Form a("plankton", 70, 71);
		
		total++;
		if (!assertEqual("getIsSigned false", false, a.getIsSigned()))
			failed++;
	}

	// getName invalid empty name
	// getGradeToSign
	{
		Form a("plankton", 70, 71);
		
		total++;
		if (!assertEqual("getGradeToSign", 70, a.getGradeToSign()))
			failed++;
	}
	// getGradeToExecute
	{
		Form a("plankton", 70, 71);
		
		total++;
		if (!assertEqual("getGradeToExecute", 71, a.getGradeToExecute()))
			failed++;
	}
	// beSigned true
	{
		Form a("plankton", 70, 71);
		Bureaucrat bob("Bob", 70);
		a.beSigned(bob);
		
		total++;
		if (!assertEqual("isSigned true", true, a.getIsSigned()))
			failed++;
	}
	// beSigned - grade too low
	{
		try
		{
			Form a("plankton", 70, 71);
			Bureaucrat bob("Bob", 75);
			a.beSigned(bob);
		}
		catch (Form::GradeTooLowException& e)
		{
			const char* expected = "Form grade too low";
			total++;
			if (!assertEqual("beSigned - grade too low", expected, e.what()))
				failed++;
		}
	}
	// beSigned - form already signed
	{
		Form a("W-4", 70, 71);
		Bureaucrat bob("Bob", 60);
		bob.signForm(a);
		std::ostringstream oss;
		std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
		try
		{
			bob.signForm(a);
		}
		catch (std::exception& e) {}
		std::cout.rdbuf(oldCout);
		const std::string expected =
			"Bob couldn't sign W-4 because Form already signed\n";
		total++;
		if (!assertEqual("beSigned - form already signed", expected, oss.str()))
			failed++;
	}
	printSummary(failed, total);
	return (failed);
}

