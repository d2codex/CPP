/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:12:04 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/18 10:31:29 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

bool initLogger(int argc, char **argv)
{
	if (argc == 1)
	{
		Logger::get().setThreshold(ERROR);
		return (true);
	}
	if (argc == 2)
	{
		logLevel level = Logger::stringToLevel(argv[1]);
		if (level == INVALID)
		{
			std::cout << red("Error. invalid log level\n");
			std::cout << cyn("usage: ./bin/<program_name> [log level]\n");
			std::cout << cyn("log levels: debug(debug build only) info warning\n");
			return (false);
		}
		#ifndef DBUG
		if (level == DEBUG)
		{
			std::cout << mag("Warning: DEBUG messages are not enabled in this build.\n");
			Logger::get().setThreshold(INFO); // fallback threshold
			return (true);
		}
		#endif
		Logger::get().setThreshold(level);
		return (true);
	}
	std::cout << cyn("usage: ./bin/<program_name> [log level]\n");
	std::cout << cyn("log levels: debug(debug build only) info warning\n");
	return (false);
}

void printTestName(const std::string& testName)
{
	std::cout << yel("======================================================\n");
	std::cout << YEL << "Testing " << testName << RESET << '\n';
}


int	main(int argc, char **argv)
{
	if (!initLogger(argc, argv))
		return (1);

	// Test Shrubbery fail form not signed
	{
		printTestName("Shrubbery - form not signed");
		try
		{
		ShrubberyCreationForm bonsai("home");
		std::cout << bonsai << '\n';

		Bureaucrat squidward("Squidward", 11);
		std::cout << squidward << '\n';

		squidward.executeForm(bonsai);
		}
		catch (std::exception& e)
		{
			LOG_ERROR() << e.what();
		}
	}
	// Test Shrubbery success
	{
		printTestName("Shrubbery - success");

		ShrubberyCreationForm bonsai("home");
		std::cout << bonsai << '\n';

		Bureaucrat squidward("Squidward", 11);
		std::cout << squidward << '\n';

		squidward.signForm(bonsai);
		squidward.executeForm(bonsai);
	}
	// Test Shrubbery fail - bureaucrat grade too low
	{
		printTestName("Shrubbery - instantiation of bureaucrat fail");
		try
		{
			ShrubberyCreationForm bonsai("home");
			std::cout << bonsai << '\n';

			Bureaucrat squidward("Squidward", 151);
			std::cout << squidward << '\n';

			squidward.signForm(bonsai);
			squidward.executeForm(bonsai);
		}
		catch (std::exception& e)
		{
			LOG_ERROR() << e.what();
		}
	}
	// Test Shrubbery fail - bureaaucrat grade too low to sign
	{
		printTestName("Shrubbery - fail");
		try
		{
			ShrubberyCreationForm bonsai("home");
			std::cout << bonsai << '\n';

			Bureaucrat squidward("Squidward", 149);
			std::cout << squidward << '\n';

			squidward.signForm(bonsai);
			squidward.executeForm(bonsai);
		}
		catch (std::exception& e)
		{
			LOG_ERROR() << e.what();
		}
	}
	// Drill 50/50 - success
	{
		printTestName("Robotomy 50/50");
		int i = 0;
		while (i < 4)
		{
			RobotomyRequestForm drill("Mr. Krabs");
			std::cout << drill << '\n';

			Bureaucrat bob("bob", 35);
			std::cout << bob << '\n';

			bob.signForm(drill);
			bob.executeForm(drill);
			i++;
		}
	}
	// Drill fail
	{
		printTestName("Robotomy - bureaucrat grade too low to sign");
		try
		{
			RobotomyRequestForm drill("Mr Krabs");
			std::cout << drill << '\n';

			Bureaucrat bob("bob", 90);
			std::cout << bob << '\n';

			bob.signForm(drill);
			bob.executeForm(drill);
		}
		catch (std::exception& e)
		{
			LOG_ERROR() << e.what();
		}
	}
	// presidential pardon request
	{
		printTestName("Pardon request - success");

		PresidentialPardonForm form("SpongeBob");
		std::cout << form << '\n';

		Bureaucrat bob("bob", 2);
		std::cout << bob << '\n';

		bob.signForm(form);
		bob.executeForm(form);
	}
	// presidential pardon request - fail form not signed
	{
		printTestName("Pardon request - fail from not signed");
		try
		{
			PresidentialPardonForm form("SpongeBob");
			std::cout << form << '\n';

			Bureaucrat bob("bob", 2);
			std::cout << bob << '\n';

			bob.executeForm(form);
		}
		catch (std::exception& e)
		{
			LOG_ERROR() << e.what();
		}
	}
	// test intern
	{
		printTestName("intern creates robotomy - subject test");
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	// test shrubbery
	{
		printTestName("intern creates shrubbery request success");
		Intern intern;
		AForm* form;

		form = intern.makeForm("shrubbery request", "Spongebob");
		std::cout << *form << std::endl;
		delete form;
	}
	// intern full flow - sign and execute success
	{
		printTestName("Intern full flow - success");

		Intern intern;
		AForm* form = intern.makeForm("robotomy request", "Bender");

		Bureaucrat boss("Boss", 1);

		boss.signForm(*form);
		boss.executeForm(*form);

		delete form;
	}
	// inter flow - fail no signing
	{
		AForm* form = NULL;
		printTestName("Intern flow -fail - execute without sign");

		try
		{
			Intern intern;
			form = intern.makeForm("shrubbery request", "home");

			Bureaucrat bob("Bob", 1);
			bob.executeForm(*form);
		}
		catch (std::exception& e)
		{
			LOG_ERROR() << e.what();
		}
		delete form;
	}
	// intern flow - fail grade too low
	{
		AForm* form = NULL;
		printTestName("Intern flow - fail - grade too low");

		try
		{
			Intern intern;
			form = intern.makeForm("presidential request", "SpongeBob");

			Bureaucrat mrKrabs("Mr Krabs", 150);

			mrKrabs.signForm(*form);
			mrKrabs.executeForm(*form);
		}
		catch (std::exception& e)
		{
			LOG_ERROR() << e.what();
		}
		delete form;
	}
}
