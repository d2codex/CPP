#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: could not open file.\n";
		return EXIT_FAILURE;
	}

	try {
		BitcoinExchange btc;
		btc.processInput(argv[1]);
	}
	catch (const std::exception& e) {
		std::cerr  << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
