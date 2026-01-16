#include "tests.hpp"
#include "colors.hpp"
#include "Weapon.hpp"
#include "utils.hpp"
#include <string>
#include <iostream>

struct WeaponTest
{
	std::string description;
	std::string typeValue;
};

void weaponTest()
{
	WeaponTest test[] = {
		{"Valid Normal case", "club"},
		{"Invalid Empty type", ""},
		{"Invalid White spaces only", "		 "},
		{"Valid complex type", "Crude Spiked Club"},
		{"Valid special characters", "afkl;j1234#$@"}
	};
	std::cout << YEL "==== Running test for weapon class ====\n" RESET;
	size_t numTests = sizeof(test) / sizeof(test[0]);
	for (size_t i = 0; i < numTests; i++)
	{
		std::cout << BLU "Test[" << i << "] " RESET << test[i].description <<'\n';

		try
		{
			Weapon weapon(test[i].typeValue);
			std::cout << "Input:   " << test[i].typeValue << '\n'
					  << "getType: " << weapon.getType() << '\n'
					  << GRN "TEST SUCCESS\n" RESET;
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Error: " << e.what() << '\n';
			if (test[i].typeValue.empty() || isBlank(test[i].typeValue))
			{
				std::cout << "Expected: " << e.what() << '\n';
				std::cout << GRN "TEST SUCCESS\n" << RESET;
			}
			else
			{
				std::cout << "Expected: " << e.what() << '\n';
				std::cout << RED "TEST FAIL\n" RESET;
			}
		}
		std::cout << '\n';
	}
	std::cout << YEL " ==== end test ====\n" RESET;
}

