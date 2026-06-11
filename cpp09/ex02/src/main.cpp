#include "../includes/PmergeMe.hpp"
#include <cstdlib>
#include <iostream>

int	main(int argc, char** argv) {
	if (argc < 1) {
		std::cerr << "Missing arguments\n";
		return EXIT_FAILURE;
	}
	try {
		PmergeMe pmerge;
		pmerge.parseInput(argc, argv);
		pmerge.sort();
	}
	catch (std::exception& e) {
		std::cerr << RED << "[ERROR] " << RESET
				  << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
