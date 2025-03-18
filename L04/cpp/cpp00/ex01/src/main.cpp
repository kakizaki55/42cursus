#include <PhoneBook.hpp>

int main(void)
{
	PhoneBook phonebook;
	Contact contact;
	std::string input;

	while(true)
	{
		phonebook.print_usages();

		std::cout << "Enter a command: ";
		std::getline(std::cin, input);

		switch (get_command(input))
		{
		case ADD:
			contact.create_contact();
			contact.print_contact();
			break;
		case SEARCH:
			std::cout << "Searching..." << std::endl;
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
