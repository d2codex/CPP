#pragma once

#include <string>

class ScalarConverter
{
public:
	enum InputType
	{
		NONE = -1,
		CHAR = 0,
		INT = 1,
		FLOAT = 2,
		DOUBLE = 3,
	};

	static void	convert(const std::string& input);

private:
	ScalarConverter();  // should not be instantiable
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	~ScalarConverter();

	static InputType getType(const std::string& input);
};
