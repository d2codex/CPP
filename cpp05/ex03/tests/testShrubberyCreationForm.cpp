/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testShrubberyCreationForm.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 00:36:59 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/18 10:06:07 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "tests.hpp"
#include "Logger.hpp"
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstdio>

int	testShrubberyCreationForm()
{
	printHeader("ShrubberyCreationForm Class");
	int	failed = 0;
	int	total = 0;

	// test ctor "Shrubbery", 145, 137
	{
		ShrubberyCreationForm a("target");

		total++;
		if (!assertEqual("default ctor - correct name",
						 "Shrubbery", a.getName()))
			failed++;

		total++;
		if (!assertEqual("default ctor - isSigned set to false", false,
						 a.getIsSigned()))
			failed++;

		total++;
		if (!assertEqual("default ctor - gradeToSign set to 145", 145,
						 a.getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("default ctor - gradeToExecute set to 137", 137,
						 a.getGradeToExecute()))
			failed++;

		total++;
		if (!assertEqual("target name is set", "target", a.getTarget()))
			failed++;

	}
	// Copy constructor
	{
		ShrubberyCreationForm a("target");
		
		Bureaucrat bob("bob", 120);
		bob.signForm(a); // isSigned should be true

		ShrubberyCreationForm b("copy");

		b = a;

		total++;
		if (!assertEqual("copy constructor copies formName", "Shrubbery",
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
		if (!assertEqual("copy constructor copies gradeToSign", 145,
					b.getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("copy constructor copies gradeToExecute", 137,
					b.getGradeToExecute()))
			failed++;
	}
	// assignment opeartor
	{
		ShrubberyCreationForm a("target");
		
		Bureaucrat bob("bob", 120);
		bob.signForm(a); // isSigned true here

		ShrubberyCreationForm b("copy"); // issigned should be false

		a = b;

		total++;
		if (!assertEqual("assignment keeps formName", "Shrubbery",
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
		if (!assertEqual("assignment keeps gradeToSign", 145,
					a.getGradeToSign()))
			failed++;

		total++;
		if (!assertEqual("assignment keeps gradeToExecute", 137,
					a.getGradeToExecute()))
			failed++;
	}
	// getTarget invalid empty target
	{
		try
		{
			ShrubberyCreationForm a("");
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
		ShrubberyCreationForm a("home");

		std::ostringstream oss;
		oss << a;
		std::string expected = 
			"Form: Shrubbery\n"
			"Signed: no\n"
			"Grade required to sign: 145\n"
			"Grade required to execute: 137";

		total++;
		if (!assertEqual("operator overload prints correct output",
						 expected, oss.str()))
			failed++;
	}
	// test executeAction success
	{
		mkdir("tests/output", 0777);
		std::string target = "tests/output/home";
		ShrubberyCreationForm a(target);
		Bureaucrat bob("bob", 10);
		bob.signForm(a);
		bob.executeForm(a);
		// Check file exists
		const std::string filename = target + "Shrubbery.txt";
		total++;
		if (!fileExists("executeAction pass", filename))
			failed++;
		else
		{
			std::remove(filename.c_str()); // cleanup
		}
	}
	// test executeAction fail - open error
	{
		std::string target = "/invalid_path/";
		ShrubberyCreationForm a(target);
		Bureaucrat bob("bob", 10);
		try
		{
			bob.signForm(a);
			bob.executeForm(a);
		}
		catch (std::exception& e)
		{
			total++;
			if (!assertEqual("executeAction fail - open error", "File open error", e.what()))
				failed++;
		}
	}
	printSummary(failed, total);
	return (failed);
}

