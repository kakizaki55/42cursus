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

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
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
	
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 0 || year > 9999)
		return (false);
	if(month < 1 || month > 12)
		return (false);
	if (month == 2 && isLeapYear(year))
	{
		if (day > 29) return false;
	} 
	else if (day > daysInMonth[month]) 
	{
		return false;
	}

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

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		if (_trimWhitespace(line) == "date,exchange_rate")
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
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}

	std::string	line;

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		if (_trimWhitespace(line) == "date | value")
			continue;

		size_t	sep = line.find('|');
		if (sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	date = _trimWhitespace(line.substr(0, sep));
		std::string	value_str = _trimWhitespace(line.substr(sep + 1));
		float	value = _parseValue(value_str);

		if (!_isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		if(_isValidValue(value_str) == false)
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
