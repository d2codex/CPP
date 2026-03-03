#include "tests.hpp"
#include "Array.hpp"
#include "Logger.hpp"

int testParamCtor()
{
	int failed = 0;
	int	total = 0;

	printHeader("Parameterized Constructor suite");
	// non const int parameterized ctor
	{
		Array<int> a(1);
		if (!assertEqual("param int - size matches", 1, a.size()))
			failed++;
		total++;
		if (!assertEqual("param int - value initialzed to 0", 0, a[0]))
			failed++;
		total++;

		bool thrown = false;
		try
		{
			a[1]; // should throw
		}
		catch (const std::out_of_range& e)
		{
			//LOG_ERROR() << e.what();
			thrown = true;
		}
		if (!assertEqual("out of bounds - a[1] should throw", true, thrown))
			failed++;
		total++;
	}
	// const int array
	{
		const Array<int> a(1);
		if (!assertEqual("const int - size matches", 1, a.size()))
			failed++;
		total++;

		bool thrown = false;
		try
		{
			a[1]; // should throw
		}
		catch (const std::out_of_range& e)
		{
			//LOG_ERROR() << e.what();
			thrown = true;
		}
		if (!assertEqual("const int - out of bounds a[1] should throw", true, thrown))
			failed++;
		total++;
	}
	// heap allocation
	{
		Array<int>* a = new Array<int>(1);
		if (!assertEqual("int (heap) - size matches", 1, a->size()))
			failed++;
		total++;
			
		bool thrown = false;
		try
		{
			(*a)[1]; // should throw
		}
		catch (const std::out_of_range& e)
		{
			//LOG_ERROR() << e.what();
			thrown = true;
		}
		if (!assertEqual("int (heap) out of bounds a[1] should throw", true, thrown))
			failed++;
		total++;
	}
	// char array
	{
		Array<char> a(5);
		if (!assertEqual("char - size matches", 5, a.size()))
			failed++;
		total++;

		if (!assertEqual("char - a[0] init to '\\0'", '\0', a[0]))
			failed++;
		total++;
	}
	// std::string array
	{
		Array<std::string> a(77);
		if (!assertEqual("std::string - size matches", 77, a.size()))
			failed++;
		total++;

		if (!assertEqual("std::string - a[76] init to empty string", "", a[76]))
			failed++;
		total++;
	}
	// float array
	{
		Array<float> a(22);
		if (!assertEqual("float - size matches", 22, a.size()))
			failed++;
		total++;

		if (!assertEqual("float - a[10] init to 0.0f", 0.0f, a[10]))
			failed++;
		total++;
	}

	printSummary(failed, total);
	return (failed);
}

