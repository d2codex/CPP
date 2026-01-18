#include "tests.hpp"
#include "colors.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>
#include <sstream>

int humanBNoWeaponTest()
{
	int passed = 0;
	int failed = 0;
	int numTests = 1;
	
    std::cout << YEL "== Running test for humanB no weapon ==\n" RESET;

	try
	{
		HumanB human("Plankton");

		// capture output
		std::streambuf* oldCout = std::cout.rdbuf();
		std::ostringstream buffer;
		std::cout.rdbuf(buffer.rdbuf());

		human.attack();

		std::cout.rdbuf(oldCout);

		std::string output = buffer.str();
		std::string expected = "Plankton attacks with their hands\n";

		std::cout << "Expected:     " << expected
			<< "Result:       " << output;
		if (expected == output)
			passed++;
		else
			failed++;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED "Error: " << e.what() << RESET << '\n';
		failed++;
	}
	
	std::cout << BLU "====== humanBNoWeaponTest summary =====" RESET << '\n'
			  << GRN "Tests passed: " << passed << RESET << '\n'
			  << RED "Tests failed: " << failed << RESET << '\n'
			  << "Total tests: " << numTests << '\n';	
	if (failed == 0)
		std::cout << GRN "All tests passed!\n" RESET;

	std::cout << BLU "=======================================\n" RESET;
	std::cout << YEL "=============END UNIT TEST=============\n" RESET;
	return (failed);
}
