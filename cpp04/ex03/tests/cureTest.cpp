/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cureTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 02:21:04 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 02:21:05 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "tests.hpp"
#include "Logger.hpp"
#include "colors.hpp"

int	cureTest()
{
	printHeader("Cure Class");
	int	failed = 0;
	int	total = 0;

	{
		Cure cure;
		total++;
		if (!assertEqual("Cure type", "cure", cure.getType()))
			failed++;
	}
	{
		Cure a;
		Cure b(a);
		total++;
		if (!assertEqual("Cure copy", a.getType(), b.getType()))
			failed++;
	}
	{
		Cure a;
		Cure b;
		b = a;
		total++;
		if (!assertEqual("Cure assignment", a.getType(), b.getType()))
			failed++;
	}
	{
		Cure a;
		AMateria* b = a.clone();

		total++;
		if(!assertEqual("Clone", a.getType(), b->getType()))
			failed++;

		total++;
		if (!assertNotEqPtr("Cure clone deep copy", &a, b))
			failed++;

		delete b;
	}
	{
		ICharacter *bob = new Character("bob");
		Cure cure;
		
		std::string expected = grn("* heals bob's wounds *\n");
		std::ostringstream oss;
		
		std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf()); // redirect cout
		cure.use(*bob); // prints into oss
		std::cout.rdbuf(oldCout); // restore cout

		total++;
		if (!assertEqual("Ice::use", expected, oss.str()))
			failed++;
		
		delete  bob;
	}

	printSummary(failed, total);
	return (failed);
}

