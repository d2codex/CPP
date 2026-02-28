#include "tests.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

int	main(void)
{
	Logger::logLevel level = Logger::DEBUG;

	Logger::get().setThreshold(level);
	LOG_DEBUG() << "test";
    std::cout << yel("=======================================\n"
					 "         Running all unit tests\n"
					 "=======================================\n");
	
	int	totalFailures = 0;
	int	totalTestSuites = 0;

	totalTestSuites++;
	totalFailures += testSwap();

	totalTestSuites++;
	totalFailures += testMin();

	totalTestSuites++;
	totalFailures += testMax();

	std::cout << blu("Test Suites Summary\n")
			  << wht("Total test suits: ") << totalTestSuites << '\n'
			  << red("total failures: ") << totalFailures << '\n'
			  << yel("=======================================\n");
	if (totalFailures == 0)
		std::cout << grn("ALL TESTS PASSED!\n");
}
