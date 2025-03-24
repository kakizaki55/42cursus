#include <PhoneBook.hpp>


bool validate_input(std::string input) {
	if (input.empty())
	{
		std::cout << "Invalid input" << std::endl;
		return (false);
	}
	return (true);
}

bool Contact::create_contact(int index)
{
	std::string input;

	this->index = index;

	std::cout << "Enter first name: ";
	std::getline(std::cin , input);
	if(validate_input(input))
		this->first_name = input;

	std::cout << "Enter last name: ";
	std::getline(std::cin , input);
	if(validate_input(input))
		this->last_name = input;

	std::cout << "Enter phone_number: ";
	std::getline(std::cin , this->phone_number);

	std::cout << "Enter nickname: ";
 	std::getline(std::cin , this->nickname);

	std::cout << "Enter darkest_secret: ";
	std::getline(std::cin , this->darkest_secret);

	return(true);
}


void Contact::display_contact()
{
	std::cout << "[" << this->index << "]" << " | " << this->first_name  <<  std::endl;
}

