#include <PhoneBook.hpp>
#include <stdio.h>

int main(void)
{
	PhoneBook phonebook;
	std::string input;

	phonebook.print_usages();

	while(true)
	{

		std::cout << "Enter a command-> ";
		std::getline(std::cin, input);

		switch (get_command(input))
		{
		case ADD:
			std::cout << "Adding..." << std::endl;
			phonebook.add();
			break;
		case SEARCH:
			std::cout << "Searching..." << std::endl;
			phonebook.index_all_contacts();
			phonebook.search();
			break;
		case EXIT:
			std::cout << "Exiting..." << std::endl;
			return(0);
		default:
			std::cout << "Invalid command" << std::endl;
			break;
		}
	}
	return (0);
}
