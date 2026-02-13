#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cerrno>
#include <climits>


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& literal)
{
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

static bool isInt(const std::string& literal)
{
	char* end;
	errno = 0;
	long val = std::strtol(literal.c_str(), &end, 10);
	return (*end == '\0' && errno == 0 && val >= INT_MIN && val <= INT_MAX);
}

static bool isFloat(const std::string& literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;
	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return false;
	char* end;
	std::strtof(literal.c_str(), &end);
	return (*end == 'f' && *(end + 1) == '\0');
}

static bool isDouble(const std::string& literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	char* end;
	std::strtod(literal.c_str(), &end);
	return (*end == '\0' && literal.find('.') != std::string::npos);
}

static void printChar(double value, bool impossible)
{
	if (impossible || std::isnan(value) || std::isinf(value))
	{
		std::cout << "char: impossible" << std::endl;
	} else if (value < 0 || value > 127) {
		std::cout << "char: impossible" << std::endl;
	} else if (value < 32 || value == 127) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		char c = value;
		std::cout << "char: '" << c << "'" << std::endl;
	}
}

static void printInt(double value, bool impossible)
{
	if (impossible || std::isnan(value) || std::isinf(value) ||
		value < INT_MIN || value > INT_MAX)
	{
		std::cout << "int: impossible" << std::endl;
	} else {
		int num = value;
		std::cout << "int: " << num << std::endl;
	}
}

static void printFloat(float value)
{
	std::cout << "float: " << value;
	if (!std::isnan(value) && !std::isinf(value))
	{
		int intVal = value;
		if (value == intVal)
			std::cout << ".0";
	}
	std::cout << "f" << std::endl;
}

static void printDouble(double value)
{
	std::cout << "double: " << value;
	if (!std::isnan(value) && !std::isinf(value))
	{
		int intVal = value;
		if (value == intVal)
			std::cout << ".0";
	}
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	double value = 0;
	bool impossible = false;

	if (isChar(literal)) {
		value = literal[1];
	} else if (isInt(literal)) {
		value = std::atoi(literal.c_str());
	} else if (isFloat(literal)) {
		value = std::strtof(literal.c_str(), NULL);
	} else if (isDouble(literal)) {
		value = std::strtod(literal.c_str(), NULL);
	} else {
		impossible = true;
	}

	printChar(value, impossible);
	printInt(value, impossible);
	float floatVal = value;
	printFloat(floatVal);
	printDouble(value);
}