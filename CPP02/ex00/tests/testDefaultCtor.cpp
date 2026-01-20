#include "Fixed.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

struct FixedRawTests
{
	std::string desc;
	int			raw;
};

int	testDefaultCtor(void)
{
	FixedRawTests test[] = {
		{"Default raw bits", 0},
		{"Positive raw bits", 42},
		{"Negative raw bits", -42},
		{"Large raw bits", 123456},
		{"Very Larg raw bits", 1234567890},
	};

	int passed = 0;
	int failed = 0;

	std::cout << YEL "===== Running test for DefaultCtor ====\n" RESET;
	size_t	numTests = sizeof(test) / sizeof(test[0]);
	for (size_t i = 0; i < numTests; i++)
	{
		FixedRawTests& t = test[i];
		std::cout << BLU "Test[" << i << "] " RESET << t.desc << '\n';
		
		Fixed a;
		a.setRawBits(t.raw);

		int result = a.getRawBits();
		std::cout << "Input:  " << t.raw << '\n';
		std::cout << "Result: " << result << '\n';

		if (result == t.raw)
		{
			std::cout << GRN "TEST PASSED\n" RESET;
			passed++;
		}
		else
		{
			std::cout << RED "TEST FAILED\n" RESET;
			failed++;
		}
		std::cout << '\n';
	}
	
	std::cout << BLU "========= DefaultCtor summary =========\n" RESET
			  << GRN "Tests passed: " << passed << RESET << '\n'
			  << RED "Tests failed: " << failed << RESET << '\n'
			  << "Total tests: " << numTests << '\n';	
	if (failed == 0)
		std::cout << GRN "All tests passed!\n" RESET;

	std::cout << BLU "=======================================\n" RESET;
	std::cout << YEL "=============END UNIT TEST=============\n" RESET;
	return (failed);
}
