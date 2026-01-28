#include "tests.hpp"
#include "Fixed.hpp"
#include "colors.hpp"

int	testSubtraction(void)
{
	printHeader("Subtraction");
	int		failed = 0;
	int		total = 0;
	Fixed	a;
	
	// int - int
	{
		a = Fixed(5) - Fixed(2);
		total++;
		if (!assertEqualFloat("int - int (+,+)", 3.0f, a.toFloat()))
			failed++;
	}
	// int - float
	{
		a = Fixed(5) - Fixed(2.5f);
		total++;
		if (!assertEqualFloat("int - float (+,+)", 2.5f, a.toFloat()))
			failed++;
	}
	// float - int
	{
		a = Fixed(7.5f) - Fixed(4);
		total++;
		if (!assertEqualFloat("float - int (+,+)", 3.5f, a.toFloat()))
			failed++;
	}
	// float - float
	{
		a = Fixed(5.5f) - Fixed(2.5f);
		total++;
		if (!assertEqualFloat("float - float (+,+)", 3.0f, a.toFloat()))
			failed++;
	}
	// + - -
	{
		a = Fixed(5) - Fixed(-2);
		total++;
		if (!assertEqualFloat("int - int (+,-)", 7.0f, a.toFloat()))
			failed++;
	}
	// - - +
	{
		a = Fixed(-5) - Fixed(3);
		total++;
		if (!assertEqualFloat("int - int (-,+)", -8.0f, a.toFloat()))
			failed++;
	}
	// - - -
	{
		a = Fixed(-3) - Fixed(-4);
		total++;
		if (!assertEqualFloat("int - int (-,-)", 1.0f, a.toFloat()))
			failed++;
	}
	// small numbers
	{
		a = Fixed(0.75f) - Fixed(0.5f);
		total++;
		if (!assertEqualFloat("small - small", 0.25f, a.toFloat()))
			failed++;
	}
	// subtract zero
	{
		a = Fixed(5) - Fixed(0);
		total++;
		if (!assertEqualFloat("int - zero", 5.0f, a.toFloat()))
			failed++;
	}
	// zero - positive
	{
		a = Fixed(0) - Fixed(5);
		total++;
		if (!assertEqualFloat("zero - positive", -5.0f, a.toFloat()))
			failed++;
	}
	// subtract from itself (result zero)
	{
		a = Fixed(3.5f) - Fixed(3.5f);
		total++;
		if (!assertEqualFloat("same - same = zero", 0.0f, a.toFloat()))
			failed++;
	}
	// larger number - smaller number
	{
		a = Fixed(100) - Fixed(25);
		total++;
		if (!assertEqualFloat("large - medium", 75.0f, a.toFloat()))
			failed++;
	}
	// smaller number - larger number (negative result)
	{
		a = Fixed(25) - Fixed(100);
		total++;
		if (!assertEqualFloat("small - large (negative)", -75.0f, a.toFloat()))
			failed++;
	}

	// subtraction overflow (positive result too large)
	{
		total++;
		try
		{
			a = Fixed(8388607) - Fixed(-8388607);
			std::cout << red("FAIL: subtraction overflow - no exception thrown");
			failed++;
		}
		catch (const std::overflow_error& e)
		{
			std::cout << grn("PASS: ")
				<< "subtraction overflow - exception caught" << '\n';
		}
		catch (...)
		{
			std::cout << red("FAIL: subtraction overflow - wrong exception type");
			failed++;
		}
	}
	// subtraction underflow (negative result too small)
	{
		total++;
		try
		{
			a = Fixed(-8388607) - Fixed(8388607);
			std::cout << red("FAIL: subtraction underflow - no exception thrown");
			failed++;
		}
		catch (const std::overflow_error& e)
		{
			std::cout << grn("PASS: ")
				<< "subtraction underflow - exception caught" << '\n';
		}
		catch (...)
		{
			std::cout << red("FAIL: subtraction underflow - wrong exception type");
			failed++;
		}
	}
	// subtraction at max boundary
	{
		total++;
		try
		{
			a = Fixed(8388607) - Fixed(-1);
			std::cout << red("FAIL: subtraction max boundary - no exception thrown");
			failed++;
		}
		catch (const std::overflow_error& e)
		{
			std::cout << grn("PASS: ")
				<< "subtraction max boundary - exception caught" << '\n';
		}
		catch (...)
		{
			std::cout << red("FAIL: subtraction max boundary - wrong exception type");
			failed++;
		}
	}
	// subtraction at min boundary
	{
		total++;
		try
		{
			a = Fixed(-8388608) - Fixed(1);
			std::cout << red("FAIL: subtraction min boundary - no exception thrown");
			failed++;
		}
		catch (const std::overflow_error& e)
		{
			std::cout << grn("PASS: ")
				<< "subtraction min boundary - exception caught" << '\n';
		}
		catch (...)
		{
			std::cout << red("FAIL: subtraction min boundary - wrong exception type");
			failed++;
		}
	}
	printSummary(failed, total);
	return (failed);
}
