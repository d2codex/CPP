#include "tests.hpp"
#include "MutantStack.hpp"
#include <list>
#include <vector>
#include <string>

int testDefaultCtor()
{
	int failed = 0;
	int	total = 0;

	printHeader("Default Constructor suite");
	// default ctor / default container
	{
		MutantStack<int> a;

		if (!assertEqual("deque<int> size 0", 0, a.size()))
			failed++;
		total++;
	}
	// default ctor / default container
	{
		MutantStack<std::string> a;

		if (!assertEqual("deque<std::string> size 0", 0, a.size()))
			failed++;
		total++;
	}
	// default ctor / default container
	{
		MutantStack<char> a;

		if (!assertEqual("deque<std::char> size 0", 0, a.size()))
			failed++;
		total++;
	}
	// list container
	{
		MutantStack<int, std::list<int> > a;

		if (!assertEqual("list<int> size 0", 0, a.size()))
			failed++;
		total++;
	}
	// vector container
	{
		MutantStack<int, std::vector<int> > a;

		if (!assertEqual("vector<int> size 0", 0, a.size()))
			failed++;
		total++;
	}
	printSummary(failed, total);
	return (failed);
}
