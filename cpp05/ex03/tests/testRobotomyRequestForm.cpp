/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testRobotomyRequestForm.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:06:01 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/18 10:06:02 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "tests.hpp"
#include "Logger.hpp"

int	testRobotomyRequestForm()
{
	printHeader("RobotomyRequestForm Class");
	int	failed = 0;
	int	total = 0;

	// test ctor "Robotomy", 145, 137
	{
		RobotomyRequestForm a("target");

		total++;
		if (!assertEqual("default ctor - correct name",
						 "Robotomy", a.getName()))
			failed++;

		total++;
		if (!assertEqual("default ctor - isSigned set to false", false,
						 a.getIsSigned()))
			failed++;

		total++;
		if (!assertEqual("default ctor - gradeToSign set to 72", 72,
						 a.getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("default ctor - gradeToExecute set to 45", 45,
						 a.getGradeToExecute()))
			failed++;

		total++;
		if (!assertEqual("target name is set", "target", a.getTarget()))
			failed++;

	}
	// Copy constructor
	{
		RobotomyRequestForm a("target");
		
		Bureaucrat bob("bob", 35);
		bob.signForm(a); // isSigned should be true

		RobotomyRequestForm b("copy");

		b = a;

		total++;
		if (!assertEqual("copy constructor copies formName", "Robotomy",
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
		if (!assertEqual("copy constructor copies gradeToSign", 72,
					b.getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("copy constructor copies gradeToExecute", 45,
					b.getGradeToExecute()))
			failed++;
	}
	// assignment opeartor
	{
		RobotomyRequestForm a("target");
		
		Bureaucrat bob("bob", 35);
		bob.signForm(a); // isSigned true here

		RobotomyRequestForm b("copy"); // issigned should be false

		a = b;

		total++;
		if (!assertEqual("assignment keeps formName", "Robotomy",
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
		if (!assertEqual("assignment keeps gradeToSign", 72,
					a.getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("assignment keeps gradeToExecute", 45,
					a.getGradeToExecute()))
			failed++;
	}
	// getTarget invalid empty target
	{
		try
		{
			RobotomyRequestForm a("");
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
		RobotomyRequestForm a("drill");

		std::ostringstream oss;
		oss << a;
		std::string expected = 
			"Form: Robotomy\n"
			"Signed: no\n"
			"Grade required to sign: 72\n"
			"Grade required to execute: 45";

		total++;
		if (!assertEqual("operator overload prints correct output",
				expected, oss.str()))
			failed++;
	}
	printSummary(failed, total);
	return (failed);
}
