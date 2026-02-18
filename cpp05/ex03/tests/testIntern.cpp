/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testIntern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:05:55 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/18 10:32:49 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "tests.hpp"
#include "Logger.hpp"

int	testIntern()
{
	printHeader("Intern Class");
	int	failed = 0;
	int	total = 0;

	// test ctor shrubbery
	{
		Intern intern;
		AForm* a = intern.makeForm("shrubbery request", "Spongebob");


		total++;
		if (!assertEqual("default ctor - correct name",
						 "Shrubbery", a->getName()))
			failed++;

		total++;
		if (!assertEqual("default ctor - isSigned set to false", false,
						 a->getIsSigned()))
			failed++;

		total++;
		if (!assertEqual("default ctor - gradeToSign set to 145", 145,
						 a->getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("default ctor - gradeToExecute set to 137", 137,
						 a->getGradeToExecute()))
			failed++;

		delete a;
	}
	// test ctor robotomy
	{
		Intern intern;
		AForm* a = intern.makeForm("robotomy request", "Spongebob");


		total++;
		if (!assertEqual("default ctor - correct name",
						 "Robotomy", a->getName()))
			failed++;

		total++;
		if (!assertEqual("default ctor - isSigned set to false", false,
						 a->getIsSigned()))
			failed++;

		total++;
		if (!assertEqual("default ctor - gradeToSign set to 72", 72,
						 a->getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("default ctor - gradeToExecute set to 45", 45,
						 a->getGradeToExecute()))
			failed++;

		delete a;
	}
	// test ctor presidential
	{
		Intern intern;
		AForm* a = intern.makeForm("presidential request", "Spongebob");


		total++;
		if (!assertEqual("default ctor - correct name",
						 "Presidential", a->getName()))
			failed++;

		total++;
		if (!assertEqual("default ctor - isSigned set to false", false,
						 a->getIsSigned()))
			failed++;

		total++;
		if (!assertEqual("default ctor - gradeToSign set to 25", 25,
						 a->getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("default ctor - gradeToExecute set to 5", 5,
						 a->getGradeToExecute()))
			failed++;
		delete a;
	}
	// invalid form name
	{
		try
		{
			Intern intern;
			AForm* a = intern.makeForm("invalid form request", "Spongebob");
			(void)a;
		}
		catch (std::exception& e)
		{
			const char* expected = "unrecognized form name: invalid form request";

			total++;
			if (!assertEqual("invalid form name", expected, e.what()))
				failed++;
		}
	}
	// empty target
	{
		try
		{
			Intern intern;
			AForm* a = intern.makeForm("robotomy request", "");
			(void)a;
		}
		catch (std::exception& e)
		{
			const char* expected = "Target cannot be empty";

			total++;
			if (!assertEqual("empty target", expected, e.what()))
				failed++;
		}
	}
	// operator overload
	{
		Intern intern;
		AForm* a = intern.makeForm("robotomy request", "Plankton");
		(void)a;

		std::ostringstream oss;
		oss << *a;
		std::string expected = 
			"Form: Robotomy\n"
			"Signed: no\n"
			"Grade required to sign: 72\n"
			"Grade required to execute: 45";

		total++;
		if (!assertEqual("operator overload prints correct output",
				expected, oss.str()))
			failed++;
		delete a;
	}
	printSummary(failed, total);
	return (failed);
}
