#pragma once

#include <string>

class ScalarConverter
{
private:
	// Private constructor to prevent instantiation
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

public:
	// Static method to convert and display the scalar value
	static void convert(const std::string& literal);
};
