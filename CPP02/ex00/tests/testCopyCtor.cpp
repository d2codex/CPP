#include "Fixed.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

int	testCopyCtor(void)
{
	int passed = 0;
	int failed = 0;
	int numTests = 1;

	std::cout << YEL "====== Running test for CopyCtor =====\n" RESET;
	Fixed original;
	original.setRawBits(21);

	Fixed copy(original);

	if (copy.getRawBits() == 21)
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
