#include "Harl.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("BLAH");
}
