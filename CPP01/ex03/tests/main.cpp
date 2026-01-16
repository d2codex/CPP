#include "tests.hpp"
#include "Weapon.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	
    std::cout << YEL << "=======================================\n"
					 << "         Running all unit tests\n"
					 << "=======================================\n\n";
	
	int	totalFailures = 0;
	int	totalTestSuites = 0;

	totalFailures += weaponTest();
	totalTestSuites++;

	std::cout << YEL "============= Test summary ============" RESET << '\n'
			  << "Result:\n"
			  << GRN "Total test suits: " << totalTestSuites << RESET << '\n'
			  << RED "total failures: " << totalFailures << RESET << '\n';
	std::cout << YEL "=======================================\n" RESET;
	if (totalFailures == 0)
		std::cout << GRN "ALL TESTS PASSED!\n" RESET;
}
