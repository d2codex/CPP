#include "tests.hpp"
#include "whatever.hpp"

int	testMin()
{
	int	failed = 0;
	int	total = 0;

	printHeader("Min suite");
	// int postive
	{
		printHeader("int postive: 2, 3");
		int a = 2;
		int b = 3;
		::min(a, b);
		assert(a < b);
		total++;
	}
	// int negative
	{
		printHeader("int negative: -2, -3");
		int a = -2;
		int b = -3;
		::min(a, b);
		assert(b < a);
		total++;
	}
	// int zero / positive
	{
		printHeader("int zero / positive: 0, 2");
		int a = 0;
		int b = 2;
		::min(a, b);
		assert(a < b);
		total++;
	}
	// int zero / negative
	{
		printHeader("int zero / negative: -2, 0");
		int a = -2;
		int b = 0;
		::min(a, b);
		assert(a < b);
		total++;
	}
	// int equal
	{
		printHeader("int negative: 5, 5 returns second");
		int a = 5;
		int b = 5;
		const int& returned = ::min(a, b);
		assert(&returned == &b);
		total++;
	}
	// float positive
	{
		printHeader("float positive 1.5f, 2.3f");
		float a = 1.5f;
		float b = 2.3f;
		::min(a, b);
		assert(a < b);
		total++;
	}
	// float negative / zero
	{
		printHeader("float mix -2.5f, 0.0f");
		float a = -2.5f;
		float b = 0.0f;
		::min(a, b);
		assert(a < b);
		total++;
	}
	// float zero / zero
	{
		printHeader("float zero 0.0f, 0.0f");
		float a = 0.0f;
		float b = 0.0f;
		const float& returned = ::min(a, b);
		assert(&returned == &b);
		total++;
	}
	// double positive
	{
		printHeader("double positive 1.5, 2.3");
		float a = 1.5;
		float b = 2.3;
		::min(a, b);
		assert(a < b);
		total++;
	}
	// double negative / zero
	{
		printHeader("double mix -2.5, 0.0");
		float a = -2.5;
		float b = 0.0;
		::min(a, b);
		assert(a < b);
		total++;
	}
	// char
	{
		printHeader("char a, z");
		char a = 'a';
		char b = 'z';
		::min(a, b);
		assert(a < b);
		total++;
	}
	// std::string
	{
		printHeader("std::string abc, def");
		std::string a = "abc";
		std::string b = "def";
		::min(a, b);
		assert(a < b);
		total++;
	}
	// std::string equal
	{
		printHeader("std::string ABC, ABC");
		std::string a = "ABC";
		std::string b = "ABC";
		const std::string& returned = ::min(a, b);
		assert(&returned == &b);
		total++;
	}
	// bool
	{
		printHeader("bool true, false");
		bool a = true;
		bool b = false;
		::min(a, b);
		assert(b < a);
		total++;
	}
	printSummary(failed, total);
	return (failed);
}

