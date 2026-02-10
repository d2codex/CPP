#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

bool initLogger(int argc, char **argv)
{
	if (argc == 1)
	{
		Logger::get().setThreshold(NONE);
		return (true);
	}
	if (argc == 2)
	{
		logLevel level = Logger::stringToLevel(argv[1]);
		if (level == INVALID)
		{
			std::cout << red("Error. invalid log level\n");
			std::cout << cyn("usage: ./bin/<program_name> [log level]\n");
			std::cout << cyn("log levels: info warning error\n");
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
	std::cout << cyn("log levels: info warning error\n");
	return (false);
}

int	main(int argc, char **argv)
{
	if (!initLogger(argc, argv))
		return (1);
/*	// Ice
	{
		std::cout << cyn("======== Test[1]: Ice ctor / dtor ========\n");
		Ice a;
	}
	// copy ctor
	{
		std::cout << cyn("======= Test[2]: copy constructor ========\n");
		Ice a;
		Ice b(a);
	}
	// Assignment Constructor
	{
		std::cout << cyn("===== Test[3]: assignment constructor ====\n");
		Ice a;
		Ice b;

		b = a;
	}
	// clone
	{
		std::cout << cyn("============= Test[4]: Clone =============\n");
		Ice a;
		AMateria* b = a.clone();

		delete b;
	}
	// Cure
	{
		std::cout << cyn("======= Test[5]: Cure ctor / dtor ========\n");
		Cure a;
	}
	// copy ctor
	{
		std::cout << cyn("======= Test[6]: copy constructor ========\n");
		Cure a;
		Cure b(a);
	}
	// Assignment Constructor
	{
		std::cout << cyn("===== Test[7]: assignment constructor ====\n");
		Cure a;
		Cure b;

		b = a;
	}
	// clone
	{
		std::cout << cyn("============= Test[8]: Clone =============\n");
		Cure a;
		AMateria* b = a.clone();

		delete b;
	}
	// Ice::use needs AMateria/ICharacter
	{
		std::cout << cyn("============ Test[9]: Ice use ============\n");
		ICharacter *bob = new Character("bob");
		Ice ice;
		ice.use(*bob);
		delete  bob;
	}
	// Ice::use needs AMateria/ICharacter
	{
		std::cout << cyn("============ Test[10]: Ice use ===========\n");
		ICharacter *bob = new Character("bob");
		Cure cure;
		cure.use(*bob);
		delete  bob;
	}
*/	// MateriaSource
	{
		std::cout << cyn("=== Test[11]: MateriaSourc ctor / dtor ===\n");
		MateriaSource a;
	}
	// MateriaSource copy
	{
		std::cout << cyn("============== Test[12]: Copy ============\n");
		MateriaSource a;
		MateriaSource b(a);
	}
	// MateriaSource assignment
	{
		std::cout << cyn("=========== Test[13]: Assignment ==========\n");
		MateriaSource a;
		MateriaSource b;

		b = a;
	}
	// learn materia
	{
		std::cout << cyn("========== Test[14]: learnMateria =========\n");
		MateriaSource a;
		a.learnMateria(new Ice());
		a.learnMateria(NULL);
		a.learnMateria(new Ice());
		a.learnMateria(new Ice());
		a.learnMateria(new Ice());
		a.learnMateria(new Ice());
	}
	// createMateria
	{
		std::cout << cyn("========= Test[15]: createMateria =========\n");
		MateriaSource a;

		AMateria* m1 = a.createMateria("fire");
		AMateria* m2 = a.createMateria("ice");
		(void)m1;
		(void)m2;
		a.learnMateria(new Ice());
		a.learnMateria(new Cure());
		AMateria* m3 = a.createMateria("ice");
		AMateria* m4 = a.createMateria("ice");
		AMateria* m5 = a.createMateria("cure");

		delete m3;
		delete m4;
		delete m5;
	}
	// SourceMateria integration
	{
		std::cout << cyn("======= Test[16]: AAnimal reference =======\n");
	}
/*	// subject test
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
*/
}
