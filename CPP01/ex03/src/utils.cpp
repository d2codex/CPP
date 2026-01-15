#include "utils.hpp"
#include <cctype>
#include <string>

bool	isBlank(const std::string& str)
{
	if (str.empty())
		return (true);
	
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			return (false);
	}
	
	return (true);
}

