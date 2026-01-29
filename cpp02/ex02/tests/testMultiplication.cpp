#include "tests.hpp"
#include "Fixed.hpp"
#include "colors.hpp"

int	testMultiplication(void)
{
	printHeader("Multiplication");

	int		failed = 0;
	int		total = 0;
	Fixed	a;

	// int * int
	{
		a = Fixed(5) * Fixed(2);
		total++;
		if (!assertEqualFloat("int * int (+,+)", 10.0f, a.toFloat()))
			failed++;
	}
	// int * float
	{
		a = Fixed(5) * Fixed(2.5f);
		total++;
		if (!assertEqualFloat("int * float (+,+)", 12.5f, a.toFloat()))
			failed++;
	}
	// float * int
	{
		a = Fixed(2.5f) * Fixed(4);
		total++;
		if (!assertEqualFloat("float * int (+,+)", 10.0f, a.toFloat()))
			failed++;
	}
	// float * float
	{
		a = Fixed(1.5f) * Fixed(2.0f);
		total++;
		if (!assertEqualFloat("float * float (+,+)", 3.0f, a.toFloat()))
			failed++;
	}
	// + * -
	{
		a = Fixed(5) * Fixed(-2);
		total++;
		if (!assertEqualFloat("int * int (+,-)", -10.0f, a.toFloat()))
			failed++;
	}
	// - * -
	{
		a = Fixed(-3) * Fixed(-4);
		total++;
		if (!assertEqualFloat("int * int (-,-)", 12.0f, a.toFloat()))
			failed++;
	}
	// small numbers
	{
		a = Fixed(0.25f) * Fixed(0.5f);
		total++;
		if (!assertEqualFloat("small * small", 0.125f, a.toFloat()))
			failed++;
	}
	// big numbers (safe range)
	{
		a = Fixed(1000) * Fixed(3);
		total++;
		if (!assertEqualFloat("big * small", 3000.0f, a.toFloat()))
			failed++;
	}
	// fail tests
	{
		total++;
		try
		{
			a = Fixed(10000) * Fixed(10000);
			std::cout << red("FAIL: multiplication overflow - no exception thrown");
			failed++;
		}
		catch (const std::overflow_error& e)
		{
			std::cout << grn("PASS: ")
					  << "multiplication overflow - exception caught" << '\n';
		}
		catch (...)
		{
			std::cout << red("FAIL: multiplication overflow - wrong exception type");
			failed++;
		}
	}
	// multiplication overflow (negative)
	{
		total++;
		try
		{
			a = Fixed(-10000) * Fixed(10000);
			std::cout << red("FAIL: multiplication overflow (negative) - no exception thrown");
			failed++;
		}
		catch (const std::overflow_error& e)
		{
			std::cout << grn("PASS: ")
					  << "multiplication overflow (negative) - exception caught" << '\n';
		}
		catch (...)
		{
			std::cout << red("FAIL: multiplication overflow (negative) - wrong exception type");
			failed++;
		}
	}
	// multiplication underflow (very negative result)
	{
		total++;
		try
		{
			a = Fixed(-10000) * Fixed(-10000);
			std::cout << red("FAIL: multiplication underflow - no exception thrown");
			failed++;
		}
		catch (const std::overflow_error& e)
		{
			std::cout << grn("PASS: ")
					  << "multiplication underflow - exception caught" << '\n';
		}
		catch (...)
		{
			std::cout << red("FAIL: multiplication underflow - wrong exception type");
			failed++;
		}
	}
	// multiplication at max safe boundary
	{
		total++;
		try
		{
			a = Fixed(8388606) * Fixed(2);
			std::cout << red("FAIL: multiplication max boundary - no exception thrown");
			failed++;
		}
		catch (const std::overflow_error& e)
		{
			std::cout << grn("PASS: ")
					  << "multiplication max boundary - exception caught" << '\n';
		}
		catch (...)
		{
			std::cout << red("FAIL: multiplication max boundary - wrong exception type");
			failed++;
		}
	}
	printSummary(failed, total);
	return (failed);
}
