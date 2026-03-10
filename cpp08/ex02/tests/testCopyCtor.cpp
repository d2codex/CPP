#include "tests.hpp"
#include "MutantStack.hpp"
#include <list>

int testCopyCtor()
{
	int failed = 0;
	int	total = 0;

	printHeader("Copy Constructor suite");
	// copy ctor / default container
	{
		MutantStack<int> a;
		a.push(42);
		MutantStack<int> b(a);

		if (!assertEqual("int - a.size == b.size", a.size(), b.size()))
			failed++;
		total++;

		if (!assertEqual("int b[0] == 42", 42, b.top()))
			failed++;
		total++;

		b.push(-42);
		if (!assertEqual("int changing b does not change a", 42, a.top()))
			failed++;
		total++;
		
		if (!assertEqual("int a.size == 1", 1, a.size()))
			failed++;
		total++;

		if (!assertEqual("int b.size == 2", 2, b.size()))
			failed++;
		total++;
	}
	// std::string with list container
	{
		MutantStack<std::string, std::list<std::string> > a;
		a.push("hello");
		a.push("world");
		MutantStack<std::string, std::list<std::string> > b(a);

		if (!assertEqual("std::string - a.size == b.size ", a.size(), b.size()))
			failed++;
		total++;
		
		if (!assertEqual("std::string b[1] == \"world\"", "world", b.top()))
			failed++;
		total++;

		b.push("Spongebob");
		if (!assertEqual("std::string changing b does not change a", "world", a.top()))
			failed++;
		total++;
		
		if (!assertEqual("std::string a.size == 2", 2, a.size()))
			failed++;
		total++;

		if (!assertEqual("int b.size == 3", 3, b.size()))
			failed++;
		total++;
	}
	printSummary(failed, total);
	return (failed);
}
