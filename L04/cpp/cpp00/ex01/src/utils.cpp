#include <PhoneBook.hpp>

Command get_command(const std::string& command)
{
	if (command == "ADD") return ADD;
	if (command == "SEARCH") return SEARCH;
	if (command == "EXIT") return EXIT;
	return INVALID;
}