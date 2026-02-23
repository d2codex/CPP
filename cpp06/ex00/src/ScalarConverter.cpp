#include "ScalarConverter.hpp"
#include "Logger.hpp"
#include <string>
#include <cctype>
#include <climits>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cfloat>
#include <cmath>
#include <limits>

/*****************************************************************************
 *                               CONSTRUCTORS                                *
 *****************************************************************************/

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{ return (*this); }
ScalarConverter::~ScalarConverter() {}

/*****************************************************************************
 *                              INTERNAL TYPES                               *
 *****************************************************************************/

struct Scalar
{
	char	c;
	int		i;
	float	f;
	double	d;
	int		impossible;
};

enum InputType
{
	NONE = -1,
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
};

enum ImpossibleFlags
{
	CHAR_IMPOSSIBLE = 1 << 0,
	INT_IMPOSSIBLE = 1 << 1,
	FLOAT_IMPOSSIBLE = 1 << 2,
	DOUBLE_IMPOSSIBLE = 1 << 3
};

/*****************************************************************************
 *                              TYPE DETECTION                               *
 *****************************************************************************/

static bool isCharType(const std::string& input)
{
	char c = input[0];
	if (input.length() == 1)
	{
		if (c >= '0' && c <= '9')
			return (false);
		else
			return (true);
	}
	if (input.length() == 3 && (input[0] == '\'' && input[2] == '\''))
		return (true);
	return (false);
}

static bool isIntType(const std::string& input)
{
	size_t len = input.length();
	size_t i = 0;

	if (input[0] == '-')
		i++;
	for (; i < len; i++)
	{
		if (!(input[i] >= '0' && input[i] <= '9'))
			return (false);
	}
	return (true);
}

static bool isFloatType(const std::string& input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (true);
	if (!input.empty() && input[input.size() - 1] != 'f')
		return (false);
	char* end;
	errno = 0;
	//this only makes sure that double is within range
	std::strtod(input.c_str(), &end);
	if (errno == ERANGE)
		return (false);
	return (end == input.c_str() + input.size() - 1);
}

static bool isDoubleType(const std::string& input)
{
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	char* end;
	errno = 0;
	std::strtod(input.c_str(), &end);
	if (errno == ERANGE)
		return (false);

	if (end != input.c_str() + input.size())
		return (false);

	if (input.find('.') == std::string::npos &&
		input.find('e') == std::string::npos &&
		input.find('E') == std::string::npos)
		return (false);
	return (true);
}

/*****************************************************************************
 *                            CONVERSION HELPERS                             *
 *****************************************************************************/

static bool	safeAtoi(const std::string& input, int* out)
{
	size_t	len = input.length();
	size_t	i = 0;
	long	result = 0;
	int		sign = 1;
	
	if (len > 11)
		return (false);
	if (input[0] == '-')
	{
		sign = -1;
		i++;
	}
	else if (input[0] == '+')
			i++;
	for(; i < len; i++)
		result = result * 10 + (input[i] - '0');
	result = result * sign;
	if (result < INT_MIN || result > INT_MAX)
		return (false);
	*out = result;
	return (true);
}

static void	convertFromChar(const std::string& input, Scalar& scalar)
{
	char c = (input.length() == 1) ? input[0] : input[1];
	scalar.c = c;
	scalar.i = static_cast<int>(c);
	scalar.f = static_cast<float>(c);
	scalar.d = static_cast<double>(c);
}

static void convertFromInt(const std::string& input, Scalar& scalar)
{
	int i;
	if (!safeAtoi(input, &i))
	{
		scalar.impossible |= CHAR_IMPOSSIBLE
						   | INT_IMPOSSIBLE
						   | FLOAT_IMPOSSIBLE
						   | DOUBLE_IMPOSSIBLE;
		return ;
	}
	if( i < 0 || i > 127)
		scalar.impossible |= CHAR_IMPOSSIBLE;
	else
		scalar.c = static_cast<char>(i);
	scalar.i = i;
	scalar.f = static_cast<float>(i);
	scalar.d = static_cast<double>(i);
}

static void convertFromFloat(const std::string& input, Scalar& scalar)
{
	std::string s = input;
	if (!s.empty() && s[s.size() - 1] == 'f')
		s.resize(s.size() - 1);

	char *end;
	double d = strtod(s.c_str(), &end);

	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		scalar.impossible |= CHAR_IMPOSSIBLE | INT_IMPOSSIBLE;
		scalar.f = static_cast<float>(d);
		scalar.d = d;
		return ;
	}

	if (d < -FLT_MAX || d > FLT_MAX)
	{
		scalar.impossible |= CHAR_IMPOSSIBLE | INT_IMPOSSIBLE | FLOAT_IMPOSSIBLE
			| DOUBLE_IMPOSSIBLE;
		return ;
	}
	scalar.f = static_cast<float>(d);
	scalar.d = d;
	scalar.i = static_cast<int>(d);
	if (scalar.i < 0 || scalar.i > 127)
		scalar.impossible |= CHAR_IMPOSSIBLE;
	else
		scalar.c = static_cast<char>(scalar.i);
}

static void convertFromDouble(const std::string& input, Scalar& scalar)
{
	char* end;
	double d = strtod(input.c_str(), &end);
	if (input == "-inf" || input == "+inf" || input == "nan")
	{
		scalar.impossible |= CHAR_IMPOSSIBLE | INT_IMPOSSIBLE;
		scalar.f = static_cast<float>(d);
		scalar.d = d;
		return ;
	}
	if (d < -FLT_MAX || d > FLT_MAX)
	{
		scalar.impossible |= CHAR_IMPOSSIBLE | INT_IMPOSSIBLE | FLOAT_IMPOSSIBLE;
		scalar.d = d;
	}
	scalar.f = static_cast<float>(d);
	scalar.d = d;
	if (d < INT_MIN || d > INT_MAX)
		scalar.impossible |= CHAR_IMPOSSIBLE | INT_IMPOSSIBLE;
	else
	{
		scalar.i = static_cast<int>(d);
		if (scalar.i < 0 || scalar.i > 127)
			scalar.impossible |= CHAR_IMPOSSIBLE;
		else
			scalar.c = static_cast<char>(scalar.i);
	}
}
/*****************************************************************************
 *                             DISPATCH HELPERS                              *
 *****************************************************************************/

typedef void (*ConvertFunction)(const std::string&, Scalar&);

ConvertFunction strategies[] =
{
	convertFromChar,
	convertFromInt,
	convertFromFloat,
	convertFromDouble
};

InputType getType(const std::string& input)
{
	if (isCharType(input))
		return (CHAR);
	if (isIntType(input))
		return (INT);
	if (isFloatType(input))
		return (FLOAT);
	if (isDoubleType(input))
		return (DOUBLE);
	return (NONE);
}

/*****************************************************************************
 *                                   OUTPUT                                  *
 *****************************************************************************/

static void printScalar(const Scalar& scalar)
{
	if (scalar.impossible & CHAR_IMPOSSIBLE)
		std::cout << "Char: impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(scalar.c)))
			std::cout << "Char: Non displayable\n";
	else
			std::cout << "Char: '" << scalar.c << "'\n";

	std::cout << std::fixed << std::setprecision(1);

	if (scalar.impossible & INT_IMPOSSIBLE)
		std::cout << "Int: impossible\n";
	else
		std::cout << "Int: " << scalar.i << '\n';

	if (scalar.impossible & FLOAT_IMPOSSIBLE)
		std::cout << "Float: impossible\n";
	else
		std::cout << "Float: " << scalar.f << "f\n";
	
	if (scalar.impossible & DOUBLE_IMPOSSIBLE)
		std::cout << "Double: impossible\n";
	else
		std::cout << "Double: " << scalar.d << '\n';
}

/*****************************************************************************
 *                              PUBLIC INTERFACE                             *
 *****************************************************************************/

void ScalarConverter::convert(const std::string& input)
{
	Scalar scalar = {}; //sets all to 0 (possible)

	if (scalar.c == '\0')
		LOG_DEBUG() << "scalar.c: null character";
	LOG_DEBUG() << "scalar.i: " << scalar.i;
	LOG_DEBUG() << "scalar.f: " << scalar.f;
	LOG_DEBUG() << "scalar.d: " << scalar.d;
	LOG_DEBUG() << "scalar impossible: " << scalar.impossible;
	LOG_DEBUG() << "raw input: " << input;

	InputType type = getType(input);
	LOG_DEBUG() << "type: " << type;
	if (type == NONE)
	{
		std::cerr << red("Error: unrecognized type\n");
		return ;
	}
	strategies[type](input, scalar);
	printScalar(scalar);
}
