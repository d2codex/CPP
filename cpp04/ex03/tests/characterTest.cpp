/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characterTest.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 02:21:01 by diade-so          #+#    #+#             */
/*   Updated: 2026/02/11 02:21:02 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "tests.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <sstream>

int	characterTest()
{
	printHeader("Character Class");
	int	failed = 0;
	int	total = 0;

	{
		Character spongebob("spongebob");
		total++;
		if (!assertEqual("ctor / dtor", "spongebob", spongebob.getName()))
			failed++;
	}
	{
		Character spongebob("spongebob");
		Character squidward("spongebob");
		total++;
		if (!assertEqual("copy", "spongebob", squidward.getName()))
			failed++;
	}
	{
		Character spongebob("spongebob");
		Character squidward("squidward");
		spongebob = squidward;
		total++;
		if (!assertEqual("assignment", "squidward", spongebob.getName()))
			failed++;
	}
	{
		ICharacter* hero = new Character("hero");
		ICharacter* target = new Character("target");

		AMateria* ice = new Ice();
		AMateria* cure = new Cure();

		//equip
		hero->equip(ice);
		hero->use(0, *target); // should trigger ice effect		
		total++;
		if(!assertEqualInt("equip ice", 0, hero->getIndex(ice)))
			failed++;

		// Equip second materia
		hero->equip(cure);
		hero->use(1, *target); // should trigger cure effect
		total++;
		if(!assertEqualInt("equip cure", 1, hero->getIndex(cure)))
			failed++;

		//unequip
		hero->unequip(0);
		total++;
		if (!assertEqualInt("unequip ice", -1, hero->getIndex(ice)))
		    failed++;

	}
/*	{
		ICharacter *bob = new Character("bob");
		Ice ice;
		std::string expected = "* shoots an ice bolt at bob *\n";
		std::ostringstream oss;
		
		std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf()); // redirect cout
		ice.use(*bob); // prints into oss
		std::cout.rdbuf(oldCout); // restore cout

		total++;
		if (!assertEqual("Ice::use", expected, oss.str()))
			failed++;
		
		delete  bob;
	}
*/
	printSummary(failed, total);
	return (failed);
}


