#include "tests.hpp"
#include "Span.hpp"
#include "Logger.hpp"

int testParamCtor()
{
	int failed = 0;
	int	total = 0;

	printHeader("Parameterized Constructor suite");
	// parameterized ctor
	{
		Span a(0);
		bool thrown = false;
		try
		{
			a.addNumber(1);
		}
		catch (Span::SpanFullException& e)
		{
			thrown = true;
		}
		if (!assertEqual("maxNumbers = 0, add should throw", true, thrown))
			failed++;
		total++;
	}
	// parameterized ctor
	{
		Span a(3);
		bool thrown = false;
		try
		{
			a.addNumber(1);
			a.addNumber(1);
			a.addNumber(1);
			a.addNumber(1);
		}
		catch (Span::SpanFullException& e)
		{
			thrown = true;
		}
		if (!assertEqual("maxNumbers = 3, add should throw", true, thrown))
			failed++;
		total++;
	}
	printSummary(failed, total);
	return (failed);
}
