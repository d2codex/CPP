#include "Bureaucrat.hpp"
#include "tests.hpp"
#include "Logger.hpp"

int	testBureaucrat()
{
	printHeader("Bureaucrat Class");
	int	failed = 0;
	int	total = 0;

	{
		std::exception* e = new Bureaucrat::GradeTooHighException();
		const char* expected = "Bureaucrat grade too high";

		total++;
		if (!assertEqual("Grade too high", expected, e->what()))
			failed++;
	}
	{
		std::exception* e = new Bureaucrat::GradeTooHighException();
		const char* expected = "Bureaucrat grade too high";

		total++;
		if (!assertNotEqual("Grade too high", expected, e->what()))
			failed++;
	}

	printSummary(failed, total);
	return (failed);
}
