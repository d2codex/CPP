#include "Weapon.hpp"
#include "HumanA.hpp"
#include "colors.hpp"
#include <iostream>



int	main(void)
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
}
