#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "tests.hpp"
#include "Logger.hpp"

int	testPresidentialPardonForm()
{
	printHeader("PresidentialPardonForm Class");
	int	failed = 0;
	int	total = 0;

	// test ctor "Presidential", 145, 137
	{
		PresidentialPardonForm a("target");

		total++;
		if (!assertEqual("default ctor - correct name",
						 "Presidential", a.getName()))
			failed++;

		total++;
		if (!assertEqual("default ctor - isSigned set to false", false,
						 a.getIsSigned()))
			failed++;

		total++;
		if (!assertEqual("default ctor - gradeToSign set to 25", 25,
						 a.getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("default ctor - gradeToExecute set to 25", 5,
						 a.getGradeToExecute()))
			failed++;

		total++;
		if (!assertEqual("target name is set", "target", a.getTarget()))
			failed++;

	}
	// Copy constructor
	{
		PresidentialPardonForm a("target");
		
		Bureaucrat bob("bob", 2);
		bob.signForm(a); // isSigned should be true

		PresidentialPardonForm b("copy");

		b = a;

		total++;
		if (!assertEqual("copy constructor copies formName", "Presidential",
					b.getName()))
			failed++;

		total++;
		if (!assertEqual("copy constructor copies target", "target",
					b.getTarget()))
			failed++;
		total++;

		if (!assertEqual("copy constructor copies isSigned", true,
					b.getIsSigned()))
			failed++;

		total++;
		if (!assertEqual("copy constructor copies gradeToSign", 25,
					b.getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("copy constructor copies gradeToExecute", 5,
					b.getGradeToExecute()))
			failed++;
	}
	// assignment opeartor
	{
		PresidentialPardonForm a("target");
		
		Bureaucrat bob("bob", 2);
		bob.signForm(a); // isSigned true here

		PresidentialPardonForm b("copy"); // issigned should be false

		a = b;

		total++;
		if (!assertEqual("assignment keeps formName", "Presidential",
					a.getName()))
			failed++;

		total++;
		if (!assertEqual("assignment copies target", "copy",
					a.getTarget()))
			failed++;

		total++;
		if (!assertEqual("assignment copies isSigned", false,
					a.getIsSigned()))
			failed++;

		total++;
		if (!assertEqual("assignment keeps gradeToSign", 25,
					a.getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("assignment keeps gradeToExecute", 5,
					a.getGradeToExecute()))
			failed++;
	}
	// getTarget invalid empty target
	{
		try
		{
			PresidentialPardonForm a("");
		}
		catch (std::exception& e)
		{
			const char* expected = "Target cannot be empty";

			total++;
			if (!assertEqual("getTarget invalid empty target", expected, e.what()))
				failed++;
		}
	}
	// operator overload
	{
		PresidentialPardonForm a("Spongebob");

		std::ostringstream oss;
		oss << a;
		std::string expected = 
			"Form: Presidential\n"
			"Signed: no\n"
			"Grade required to sign: 25\n"
			"Grade required to execute: 5";

		total++;
		if (!assertEqual("operator overload prints correct output",
				expected, oss.str()))
			failed++;
	}
	printSummary(failed, total);
	return (failed);
}
