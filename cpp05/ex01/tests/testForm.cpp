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
		if (!assertEqual("exception GradeTooHighException returns correct message",
						 expected, e->what()))
			failed++;
		delete e;
	}
	// Class test: Exception too low returns correct message
	{
		std::exception* e = new Form::GradeTooLowException();
		const char* expected = "Form grade too low";

		total++;
		if (!assertEqual("exception GradeTooLowException returns correct message",
						 expected, e->what()))
			failed++;
		delete e;
	}
	// Class test: Exception form already signed returns correct message
	{
		std::exception* e = new Form::FormAlreadySigned();
		const char* expected = "Form already signed";

		total++;
		if (!assertEqual("exception FormAlreadySigned returns correct message",
						 expected, e->what()))
			failed++;
		delete e;
	}
	// Class test: Exception GradeTooLowToSign returns correct message
	{
		std::exception* e = new Form::GradeTooLowToSign();
		const char* expected = "Bureaucrat grade too low to sign";

		total++;
		if (!assertEqual("exception GradeTooLowToSign returns correct message",
						 expected, e->what()))
			failed++;
		delete e;
	}
	// test default constructor formName, isSigned, gradeToSign, gradeToExecute
	{
		Form a;

		total++;
		if (!assertEqual("default ctor formName matches", "default", a.getName()))
			failed++;

		total++;
		if (!assertEqual("default ctor isSigned matches", false, a.getIsSigned()))
			failed++;

		total++;
		if (!assertEqual("default ctor gradeToSign matches", 150, a.getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("default ctor gradeToExecute matches", 150, a.getGradeToExecute()))
			failed++;
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
			if (!assertEqual("execute grade too high - out of range", expected, e.what()))
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
		catch (Form::GradeTooLowToSign& e)
		{
			const char* expected = "Bureaucrat grade too low to sign";
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
	// copy constructor
	{
		Form original("Sandy", 42, 150);
		Form copy(original);

		total++;
		if (!assertEqual("copy constructor copies formName",
					original.getName(), copy.getName()))
			failed++;

		total++;
		if (!assertEqual("copy constructor copies isSigned",
					original.getIsSigned(), copy.getIsSigned()))
			failed++;

		total++;
		if (!assertEqual("copy constructor copies gradeToSign",
					original.getGradeToSign(), copy.getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("copy constructor copies gradeToExecute",
					original.getGradeToExecute(), copy.getGradeToExecute()))
			failed++;
	}
	// assignment operator
	{
		Bureaucrat bob("Bob", 25);

		Form a("1040", 100, 138);
		bob.signForm(a); // isSigned form a should be set to true now
		Form b("W-2", 50, 78); // issigned set to false

		b = a; // copy to original

		total++;
		if (!assertEqual("copy assignment copies isSigned", a.getIsSigned(),
					b.getIsSigned()))
			failed++;

		total++;
		if (!assertEqual("copy assignment keeps original formName",
					std::string("W-2"), b.getName()))
			failed++;

		total++;
		if (!assertEqual("copy assignment keeps original gradeToSign ",
					50, b.getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("copy assignment keeps original name",
					78, b.getGradeToExecute()))
			failed++;
	}
	// operator overload
	{
		Form tax("W-2", 32, 99);

		std::ostringstream oss;
		oss << tax;
		std::string expected =
			"Form: W-2\n"
			"Signed: no\n"
			"Grade required to sign: 32\n"
			"Grade required to execute: 99";
		
		total++;
		if (!assertEqual("operator overload prints correct message",
						 expected, oss.str()))
			failed++;
	}
	printSummary(failed, total);
	return (failed);
}

