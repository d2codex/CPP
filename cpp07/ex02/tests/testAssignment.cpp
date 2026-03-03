#include "tests.hpp"
#include "Array.hpp"
#include "Logger.hpp"

int testAssignment()
{
	int failed = 0;
	int	total = 0;

	printHeader("Assignment Overload suite");
	// non const int parameterized ctor
	{
		Array<int> a(1);
		a[0] = 42;
		Array<int> b;

		b = a;

		if (!assertEqual("int (nconst/nconst) - copy size", a.size(), b.size()))
			failed++;
		total++;

		if (!assertEqual("int (nconst/nconst) - copy value", a[0], b[0]))
			failed++;
		total++;

		if (!assertEqual("int (nconst/nconst) - deep copy", 42, b[0]))
			failed++;
		total++;

		b[0] = 100;

		if (!assertEqual("modifingy b does not modify a", 42, a[0]))
			failed++;
		total++;
	}
	// std string array non const/ const
	{
		const Array<std::string> a(1);
		// a[0] = "hello world";
		Array<std::string> b;

		b = a;

		if (!assertEqual("std::string (const/nconst) - copy size", a.size(), b.size()))
			failed++;
		total++;

		if (!assertEqual("std::string (const/nconst) - copy value", a[0], b[0]))
			failed++;
		total++;

		b[0] = "Spongebob";

		if (!assertEqual("modifingy b does not modify a", "", a[0]))
			failed++;
		total++;
	}
	// assign empty array to non-empty
	{
		Array<int> empty;
		Array<int> full(2);
		full[0] = 7;
		full[1] = 8;
		full = empty;

		if (!assertEqual("assign empty array size", 0u, full.size()))
			failed++;
		total++;
	}

	printSummary(failed, total);
	return (failed);
}

