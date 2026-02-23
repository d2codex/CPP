#pragma once

#include <string>

class ScalarConverter
{
public:
	static void	convert(const std::string& input);

private:
	ScalarConverter();  // should not be instantiable
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	~ScalarConverter();
};
