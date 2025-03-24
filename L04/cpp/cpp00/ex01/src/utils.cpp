#include <PhoneBook.hpp>
#include <iomanip>

Command get_command(const std::string& command)
{
	if (command == "ADD") return ADD;
	if (command == "SEARCH") return SEARCH;
	if (command == "EXIT") return EXIT;
	return INVALID;
}


bool is_number(const std::string& string)
{
	for (size_t i = 0; i < string.length(); i++)
	{
		if (!std::isdigit(string[i]))
			return false;
	}
	return true;
}

void truncate_and_print(const std::string& str, int width)
{
	if (str.length() > width) {
		std::cout << std::setw(width - 1) << std::right << str.substr(0, width - 1) + "." << "|";
	} else {
		std::cout << std::setw(width) << std::right << str << "|";
	}
}