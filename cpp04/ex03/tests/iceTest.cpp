/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iceTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 02:21:08 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 02:21:09 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Character.hpp"
#include "tests.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <sstream>

int	iceTest()
{
	printHeader("Ice Class");
	int	failed = 0;
	int	total = 0;

	{
		Ice ice;
		total++;
		if (!assertEqual("Ice type", "ice", ice.getType()))
			failed++;
	}
	{
		Ice a;
		Ice b(a);
		total++;
		if (!assertEqual("Ice copy", a.getType(), b.getType()))
			failed++;
	}
	{
		Ice a;
		Ice b;
		b = a;
		total++;
		if (!assertEqual("Ice assignment", a.getType(), b.getType()))
			failed++;
	}
	{
		Ice a;
		AMateria* b = a.clone();

		total++;
		if(!assertEqual("Clone", a.getType(), b->getType()))
			failed++;

		total++;
		if (!assertNotEqPtr("Ice clone deep copy", &a, b))
			failed++;

		delete b;
	}
	{
		ICharacter *bob = new Character("bob");
		Ice ice;
		std::string expected = red("* shoots an ice bolt at bob *\n");
		
		std::ostringstream oss;
		std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf()); // redirect cout
		
		ice.use(*bob); // prints into oss
		
		std::cout.rdbuf(oldCout); // restore cout

		total++;
		if (!assertEqual("Ice::use", expected, oss.str()))
			failed++;
		
		delete  bob;
	}

	printSummary(failed, total);
	return (failed);
}
