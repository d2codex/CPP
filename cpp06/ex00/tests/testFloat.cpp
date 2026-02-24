#include "tests.hpp"
#include "ScalarConverter.hpp"
#include <cmath>

int	testFloat()
{
	int	failed = 0;
	int	total = 0;

	printHeader("Float Suite");
	// test int 0
	{
		printHeader("float 0.0f");
		ScalarConverter::Scalar s = ScalarConverter::convert("0.0f");

		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 0);
		assert(s.f == 0.0f);
		assert(s.d == 0.0);
		total++;
	}
	// highest displayable char 126
	{
		printHeader("highest displayable char 126.0f");
		ScalarConverter::Scalar s = ScalarConverter::convert("126.0f");

		assert(s.c == '~');
		assert(s.i == 126);
		assert(s.f == 126.0f);
		assert(s.d == 126.0);
		total++;
	}
	// non displayable 127
	{
		printHeader("non displayable 127.0f");
		ScalarConverter::Scalar s = ScalarConverter::convert("127.0f");

		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 127);
		assert(s.f == 127.0f);
		assert(s.d == 127.0);
		total++;
	}
	// char impossible 128
	{
		printHeader("char impossible 128.0f");
		ScalarConverter::Scalar s = ScalarConverter::convert("128.0f");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.i == 128);
		assert(s.f == 128.0f);
		assert(s.d == 128.0);
		total++;
	}
	// lowest displayable char 32
	{
		printHeader("lowest displayable char 32.0f");
		ScalarConverter::Scalar s = ScalarConverter::convert("32.0f");

		assert(s.c == ' ');
		assert(s.i == 32);
		assert(s.f == 32.0f);
		assert(s.d == 32.0);
		total++;
	}
	// non displayable 31
	{
		printHeader("non displayable 31.0f");
		ScalarConverter::Scalar s = ScalarConverter::convert("31.0f");

		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 31);
		assert(s.f == 31.0f);
		assert(s.d == 31.0);
		total++;
	}
	// char impossible negative -1
	{
		printHeader("char impossible (neg) -1.0f");
		ScalarConverter::Scalar s = ScalarConverter::convert("-1.0f");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.i == -1);
		assert(s.f == -1.0f);
		assert(s.d == -1.0);
		total++;
	}
	// int max
	{
		printHeader("int max 2147483647.0f");
		ScalarConverter::Scalar s = ScalarConverter::convert("2147483647.0f");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.i == 2147483647);
		assert(s.f == 2147483647.0f);
		assert(s.d == 2147483647.0);
		total++;
	}
	// int min
	{
		printHeader("int min -2147483648.0f");
		ScalarConverter::Scalar s = ScalarConverter::convert("-2147483648.0f");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.i == -2147483648);
		assert(s.f == -2147483648.0f);
		assert(s.d == -2147483648.0);
		total++;
	}
	// int overflow
	{
		printHeader("int overflow 2147483648.0f");
		ScalarConverter::Scalar s = ScalarConverter::convert("2147483648.0f");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(s.f == 2147483648.0f);
		assert(s.d == 2147483648.0);
		total++;
	}
	// int underflow
	{
		printHeader("int underflow -2147483649.0f");
		ScalarConverter::Scalar s = ScalarConverter::convert("-2147483649.0f");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(s.f == -2147483649.0f);
		assert(s.d == -2147483649.0);
		total++;
	}

	// FLT_MAX
	{
		printHeader("FLT_MAX 3.40282e+38f");
		ScalarConverter::Scalar s = ScalarConverter::convert("3.40282e+38f");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(s.f == 3.40282e+38f);
		assert(s.d == 3.40282e+38);
		total++;
	}
	// -FLT_MAX
	{
		printHeader("-FLT_MAX -3.40282e+38f");
		ScalarConverter::Scalar s = ScalarConverter::convert("-3.40282e+38f");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(s.f == -3.40282e+38f);
		assert(s.d == -3.40282e+38);
		total++;
	}
	// FLT_MIN
	{
		printHeader("FLT_MIN 1.17549435e-38f");
		ScalarConverter::Scalar s = ScalarConverter::convert("1.17549435e-38f");

		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 0);
		assert(s.f == 1.17549435e-38f);
		assert(s.d == 1.17549435e-38);
		total++;
	}
	// -FLT_MIN
	{
		printHeader("-FLT_MIN -1.17549435e-38f");
		ScalarConverter::Scalar s = ScalarConverter::convert("-1.17549435e-38f");

		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 0);
		assert(s.f == -1.17549435e-38f);
		assert(s.d == -1.17549435e-38);
		total++;
	}
	// float overflow lowercase e
	{
		printHeader("float overflow expect throw 3.40283e+38f");
		expect_throw("3.40283e+38f");
		total++;
	}
	// float underflow capitla E
	{
		printHeader("float underflow expect throw -3.40283E+38f");
		expect_throw("-3.40283E+38f");
		total++;
	}
	// float number no dot
	{
		printHeader("float number no dot 123456f");
		ScalarConverter::Scalar s = ScalarConverter::convert("123456f");
		
		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.i == 123456);
		assert(s.f == 123456.0f);
		assert(s.d == 123456.0);
		total++;
	}
	// float number leading dot
	{
		printHeader("float number leading dot .123456f");
		ScalarConverter::Scalar s = ScalarConverter::convert(".123456f");
		
		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 0);
		assert(almostEqual(s.f, 0.123456f, 1e-5f));
		assert(almostEqual(s.d, 0.123456, 1e-10));
		total++;
	}
		// float lots of number after dot
	{
		printHeader("float lots of numbers after dot .123456789f");
		ScalarConverter::Scalar s = ScalarConverter::convert(".123456789f");
		
		assert(s.impossible & ScalarConverter::CHAR_NONDISPLAYABLE);
		assert(s.i == 0);
		assert(almostEqual(s.f, 0.123456789f, 1e-5f));
		assert(almostEqual(s.d, 0.123456789, 1e-10));
		total++;
	}

	// float literals -inff
	{
		printHeader("float litteral -inff");
		ScalarConverter::Scalar s = ScalarConverter::convert("-inff");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(std::isinf(s.f) && s.f < 0);
		assert(std::isinf(s.d) && s.d < 0);
		total++;
	}
	// float literals +inff
	{
		printHeader("float litteral +inff");
		ScalarConverter::Scalar s = ScalarConverter::convert("+inff");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(std::isinf(s.f) && s.f > 0);
		assert(std::isinf(s.d) && s.d > 0);
		total++;
	}
	// float literals nanf
	{
		printHeader("float litteral nanf");
		ScalarConverter::Scalar s = ScalarConverter::convert("nanf");

		assert(s.impossible & ScalarConverter::CHAR_IMPOSSIBLE);
		assert(s.impossible & ScalarConverter::INT_IMPOSSIBLE);
		assert(std::isnan(s.f));
		assert(std::isnan(s.d));
		total++;
	}

	printSummary(failed, total);
	return (failed);
}
