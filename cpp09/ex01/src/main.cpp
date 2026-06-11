#include "../includes/RPN.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Invalid number of arguments\n";
		return EXIT_FAILURE;
	}
	RPN rpn;
	try {
		std::cout << rpn.evaluate(argv[1]) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << RED << "[ERROR] " << RESET
				  << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
