#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_database = other._database;
	}
	return (*this);
}

bool	BitcoinExchange::_isValidDate(const std::string &date)
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return (false);
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 0 || year > 2027)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);

	return (true);
}

std::string	BitcoinExchange::_trimWhitespace(const std::string &str)
{
	size_t	start = 0;
	size_t	end = str.length();

	while (start < end && (str[start] == ' ' || str[start] == '\t'))
		start++;
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
		end--;

	return (str.substr(start, end - start));
}

float	BitcoinExchange::_parseValue(const std::string &value)
{
	char	*endptr;
	float	result = std::strtof(value.c_str(), &endptr);

	if (*endptr != '\0')
		return (-1.0f);

	return (result);
}

bool	BitcoinExchange::_isValidValue(const std::string &value)
{
	float	val = _parseValue(value);

	if (val < 0 || val > 1000)
		return (false);

	return (true);
}

bool	BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream	file(filename.c_str());

	if (!file.is_open())
		return (false);

	std::string	line;
	std::getline(file, line); // Skip header

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		size_t	sep = line.find(',');
		if (sep == std::string::npos)
			continue;

		std::string	date = line.substr(0, sep);
		std::string	price_str = line.substr(sep + 1);

		char	*endptr;
		float	price = std::strtof(price_str.c_str(), &endptr);

		this->_database[date] = price;
	}

	file.close();
	return (true);
}

void	BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream	file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string	line;
	std::getline(file, line); // Skip header

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		size_t	sep = line.find('|');
		if (sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	date = _trimWhitespace(line.substr(0, sep));
		std::string	value_str = _trimWhitespace(line.substr(sep + 1));

		if (!_isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		float	value = _parseValue(value_str);

		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator	it = this->_database.lower_bound(date);

		if (it != this->_database.begin() && (it == this->_database.end() || it->first != date))
			--it;

		if (it == this->_database.end() || it->first > date)
		{
			std::cout << "Error: bad input dont have data this date => " << date << std::endl;
			continue;
		}

		float	result = value * it->second;

		std::cout << date << " => " << value << " = " << result << std::endl;
	}

	file.close();
}
