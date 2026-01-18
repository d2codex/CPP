#include "tests.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	
    std::cout << YEL << "=======================================\n"
					 << "         Running all unit tests\n"
					 << "=======================================\n";
	
	int	totalFailures = 0;
	int	totalTestSuites = 0;

	if (replaceLineTest())
		totalTestSuites++;
	else
		totalFailures++;

	std::cout << YEL "============= Test summary ============" RESET << '\n'
			  << WHT "Total test suits: " << totalTestSuites << RESET << '\n'
			  << RED "total failures: " << totalFailures << RESET << '\n';
	std::cout << YEL "=======================================\n" RESET;
	if (totalFailures == 0)
		std::cout << GRN "ALL TESTS PASSED!\n" RESET;
}
