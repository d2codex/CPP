#include "tests.hpp"
#include "ScalarConverter.hpp"

int	testChar()
{
	//printHeader("Char");
	int	failed = 0;
	int	total = 0;

	printHeader("Char Suite");
	// test char 0
	{
		printHeader("char - '0'");
		ScalarConverter::Scalar s = ScalarConverter::convert("'0'");

		assert(s.c == '0');
		assert(s.i == 48);
		assert(s.f == 48.0f);
		assert(s.d == 48.0);
		total++;
	}
	// test letter lowercase a
	{
		printHeader("letter lowercase a");
		ScalarConverter::Scalar s = ScalarConverter::convert("a");

		assert(s.c == 'a');
		assert(s.i == 97);
		assert(s.f == 97.0f);
		assert(s.d == 97.0);
		total++;
	}
	// test letter uppercase Z
	{
		printHeader("letter uppercase Z");
		ScalarConverter::Scalar s = ScalarConverter::convert("Z");

		assert(s.c == 'Z');
		assert(s.i == 90);
		assert(s.f == 90.0f);
		assert(s.d == 90.0);
		total++;
	}
	// test space
	{
		printHeader("space displayable ' '");
		ScalarConverter::Scalar s = ScalarConverter::convert(" ");

		assert(s.c == ' ');
		assert(s.i == 32);
		assert(s.f == 32.0f);
		assert(s.d == 32.0);
		total++;
	}
	// highest printable char
	{
		printHeader("highest printable char ~");
		ScalarConverter::Scalar s = ScalarConverter::convert("~");

		assert(s.c == '~');
		assert(s.i == 126);
		assert(s.f == 126.0f);
		assert(s.d == 126.0);
		total++;
	}
	// non displayable chars - unrecognized type
	{
		printHeader("non displayble should throw - \\t ");
		expect_throw("\\t");
		total++;
	}
	// empty - should throw
	{
		printHeader("empty should throw");
		expect_throw("");
		total++;
	}
	// invalid input - should throw
	{
		printHeader("invalid input should throw - 123abc");
		expect_throw("123abc");
		total++;
	}
	printSummary(failed, total);
	return (failed);
}
