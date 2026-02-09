#include "Ice.hpp"
#include "tests.hpp"
#include "Logger.hpp"
#include "colors.hpp"

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
	}

	printSummary(failed, total);
	return (failed);
}
