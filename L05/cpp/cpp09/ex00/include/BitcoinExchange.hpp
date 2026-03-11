#pragma once

#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_database;

		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		bool		_isValidDate(const std::string &date);
		bool		_isValidValue(const std::string &value);
		float		_parseValue(const std::string &value);
		std::string	_trimWhitespace(const std::string &str);

	public:
		BitcoinExchange();
		~BitcoinExchange();

		bool	loadDatabase(const std::string &filename);
		void	processInput(const std::string &filename);
};

