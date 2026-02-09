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
	}

	printSummary(failed, total);
	return (failed);
}

