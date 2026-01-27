#include <iostream>
#include <ctime>
#include <iomanip>

int	main(void)
{
	// gets the seconds elapsed since unix epoch
	std::time_t epochTime = std::time(nullptr);
	std::cout << "stored in epochTime: " << epochTime << std::endl;
	// we can also write it as
	std::time_t current;
	std::time(&current);
	std::cout << "stored in current :" << current << std::endl;

	// but this information is not human-read friendly so...
	// we extract the information from std::tm using std::localtime()
	std::tm* now = std::localtime(&epochTime);

	std::cout << "Year:    " << (now->tm_year + 1900) << std::endl
			  << "Month:   " << std::setw(4) << (now->tm_mon + 1) << std::endl
			  << "Day:     " << std::setw(4) << now->tm_mday << std::endl
			  << "Hour:    " << std::setw(4) << now->tm_hour << std::endl
			  << "Minutes: " << std::setw(4) << now->tm_min << std::endl
			  << "Seconds: " << std::setw(4) << now->tm_sec << std::endl;
}
