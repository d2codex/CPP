#include "tests.hpp"
#include "colors.hpp"
#include "Weapon.hpp"
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
	size_t numTests = sizeof(test) / sizeof(test[0]);
	for (size_t i = 0; i < numTests; i++)
	{
		std::cout << YEL "Test[" << i << "] " << test[i].description
			<< RESET <<'\n';

		try
		{
			Weapon weapon(test[i].typeValue);
			std::cout << "Input:   " << test[i].typeValue << '\n';
			std::cout << "getType: " << weapon.getType() << '\n';
			if (weapon.getType() == test[i].typeValue)
				std::cout << GRN "Success\n" RESET;
			else
				std::cout << RED "Fail: type mismatch\n";
		}
		catch (const std::exception& e)
		{
			std::cerr << RED "Error: " << e.what() << RESET << '\n';
		}
	}
}

