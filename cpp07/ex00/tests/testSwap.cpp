#include "tests.hpp"
#include "whatever.hpp"
#include <ostream>

struct Point
{
	int x;
	int y;
};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int	testSwap()
{
	int	failed = 0;
	int	total = 0;

	printHeader("Swap suite");
	// test int positive
	{
		printHeader("testing int postive...");
		int a = 2;
		int b = 3;
		::swap(a, b);
		assert(a == 3);
		assert(b == 2);
		total++;
	}
	// test int negative
	{
		printHeader("testing int negative...");
		int a = -2;
		int b = -3;
		::swap(a, b);
		assert(a == -3);
		assert(b == -2);
		total++;
	}
	// test int zero
	{
		printHeader("testing int zero...");
		int a = 0;
		int b = 0;
		::swap(a, b);
		assert(a == 0);
		assert(b == 0);
		total++;
	}
	// test float
	{
		printHeader("testing float...");
		float a = -2.f;
		float b = 25.00f;
		::swap(a, b);
		assert(a == 25.00f);
		assert(b == -2.f);
		total++;
	}
	// test double
	{
		printHeader("testing double...");
		double a = 10.0;
		double b = -25.00;
		::swap(a, b);
		assert(a == -25.00);
		assert(b == 10.0);
		total++;
	}
	// test char
	{
		printHeader("testing char...");
		char a = 'z';
		char b = 'm';
		::swap(a, b);
		assert(a == 'm');
		assert(b == 'z');
		total++;
	}
	// test bool
	{
		printHeader("testing bool...");
		bool a = true;
		bool b = false;
		::swap(a, b);
		assert(a == false);
		assert(b == true);
		total++;
	}
	// test std::string
	{
		printHeader("testing std::string...");
		std::string a = "hello";
		std::string b = "world";
		::swap(a, b);
		assert(a == "world");
		assert(b == "hello");
		total++;
	}
	// test struct
	{
		printHeader("testing struct...");
	
		Point a = {1, 2};
		Point b = {3, 4};
		::swap(a, b);
		assert(a.x == 3);
		assert(a.y == 4);
		assert(b.x == 1);
		assert(b.y == 2);
		total++;
	}
	printSummary(failed, total);
	return (failed);
}
