#pragma once

#include <string>

/**
 * @brief Converts a string input to scalar types.
 *
 * Provides conversion to char, int, float, and double.
 * Uses flags to indicate impossible or non-displayable values.
 */
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

	enum ImpossibleFlags
	{
		CHAR_IMPOSSIBLE = 1 << 0,
		INT_IMPOSSIBLE = 1 << 1,
		FLOAT_IMPOSSIBLE = 1 << 2,
		DOUBLE_IMPOSSIBLE = 1 << 3,
		CHAR_NONDISPLAYABLE = 1 << 4,
	};

	static Scalar	convert(const std::string& input);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	~ScalarConverter();
};
