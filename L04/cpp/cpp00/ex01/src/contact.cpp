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


void Contact::index_self()
{
	std::cout << "[" << this->index << "]" << " | " << this->first_name  <<  std::endl;
}


bool Contact::display_self()
{
	std:: cout << "Nickname: " << this->nickname << std::endl;
	std:: cout << "First name: " << this->first_name << std::endl;
	std:: cout << "Last name: " << this->last_name << std::endl;
	std:: cout << "Phone number:" << this->phone_number << std::endl;
	std:: cout << "Darkest secret:" << std::endl;

	return(true);
}

