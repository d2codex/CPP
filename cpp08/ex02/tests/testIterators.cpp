#include "tests.hpp"
#include "MutantStack.hpp"
#include <list>

int testIterators()
{
	int failed = 0;
	int	total = 0;

	printHeader("Iterators suite");
	// non const iterators
	{
		MutantStack<int> a;
		a.push(42);
		a.push(6);
		a.push(76);
		a.push(-32);
		a.push(0);
		a.push(24);
		a.push(-71);

		// rbegin rend values
		if (!assertEqual("nconst begin value matches", 42, *a.begin()))
			failed++;
		total++;

		//forward iterator
		MutantStack<int>::iterator it = a.begin();
		while (it != a.end())
			++it;
		if (!assertEqual("nconst iterator reached end ", true, it == a.end()))
			failed++;
		total++;

		// rbegin rend values
		if (!assertEqual("nconst rbegin value matches", -71, *a.rbegin()))
			failed++;
		total++;

		// reverse iterator
		MutantStack<int>::reverse_iterator	reverse_it = a.rbegin();
		while (reverse_it != a.rend())
			++reverse_it;
		if (!assertEqual("nconst reverse iterator reached rend", true, reverse_it == a.rend()))
			failed++;
		total++;

	}
	// const iterators
	{
		MutantStack<int> a;
		a.push(42);
		a.push(6);
		a.push(76);
		a.push(-32);
		a.push(0);
		a.push(24);
		a.push(-71);

		const MutantStack<int>& ca = a;
		// rbegin rend values
		if (!assertEqual("const begin value matches", 42, *ca.begin()))
			failed++;
		total++;

		//forward iterator
		MutantStack<int>::const_iterator it = ca.begin();
		while (it != ca.end())
			++it;
		if (!assertEqual("const iterator reached end ", true, it == ca.end()))
			failed++;
		total++;

		// rbegin rend values
		if (!assertEqual("const rbegin value matches", -71, *ca.rbegin()))
			failed++;
		total++;

		// reverse iterator
		MutantStack<int>::const_reverse_iterator	reverse_it = ca.rbegin();
		while (reverse_it != ca.rend())
			++reverse_it;
		if (!assertEqual("const reverse iterator reached rend", true, reverse_it == ca.rend()))
			failed++;
		total++;
	}

	printSummary(failed, total);
	return (failed);
}

