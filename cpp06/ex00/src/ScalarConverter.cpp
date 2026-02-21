#include "ScalarConverter.hpp"
#include "Logger.hpp"
#include <string>
#include <cctype>
#include <climits>
#include <iostream>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{ return (*this); }
ScalarConverter::~ScalarConverter() {}

struct Scalar
{
	char	c;
	int		i;
	float	f;
	double	d;
};

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

	for (size_t i = 0; i < len; i++)
	{
		if (input[0] == '-')
			i++;
		if (input[i] >= '0' && input[i] <= '9')
			return (true);
	}
	return (false);
}

//static bool isFloatType(const std::string& input)
//static bool isDoubleType(const std::string& input)

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

	if (result < INT_MIN || result > INT_MAX)
		return (false);
	*out = result * sign;
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
		// marke as impossible
		return ;
	}
	scalar.c = (i >= 0 && i <= 127) ? static_cast<char>(i) : 0;
	scalar.i = i;
	scalar.f = static_cast<float>(i);
	scalar.d = static_cast<double>(i);
}

static void convertFromDouble(const std::string& input, Scalar& scalar)
{
	(void)input;
	(void)scalar;
	LOG_INFO() << "print stuff here";
}

ScalarConverter::InputType ScalarConverter::getType(const std::string& input)
{
	if (isCharType(input))
		return (ScalarConverter::CHAR);
	if (isIntType(input))
		return (ScalarConverter::INT);
/*	if (isFloatType(input))
		return (FLOAT);
	if (isDoubleType(input))
		return (DOUBLE;)
*/
	return (ScalarConverter::NONE);
}

typedef void (*ConvertFunction)(const std::string&, Scalar&);

ConvertFunction strategies[] =
{
	convertFromChar,
	convertFromInt,
	convertFromDouble
};

static void printScalar(const Scalar& scalar)
{
	
	if (scalar.i >= 32 && scalar.i < 127)
	{
		if (std::isprint(static_cast<unsigned char>(scalar.c)))
			std::cout << "Char: '" << scalar.c << "'\n";
		else
			std::cout << "Char: Non displayable\n";
	}
	else
		std::cout << "Char: impossible\n";

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Int: " << scalar.i << '\n';
	std::cout << "Float: " << scalar.f << "f\n";
	std::cout << "Double: " << scalar.d << '\n';
}

void ScalarConverter::convert(const std::string& input)
{
	Scalar scalar;
	LOG_DEBUG() << "raw input: " << input;

	ScalarConverter::InputType type = getType(input);
	if (type >= ScalarConverter::CHAR)
		strategies[type](input, scalar);
	printScalar(scalar);
}
