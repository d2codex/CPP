#include "ScalarConverter.hpp"
#include "Logger.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{ return (*this); }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& input)
{
	std::cout << "raw input: " << input << std::endl;
	LOG_DEBUG() << "received input: " << input;
}
