#pragma once

#include <string>

class ScalarConverter
{
public:	
	struct Scalar
	{
		char	c;
		int		i;
		float	f;
		double	d;
		int		impossible;
	};

	static Scalar	convert(const std::string& input);

private:
	ScalarConverter();  // should not be instantiable
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	~ScalarConverter();
};
