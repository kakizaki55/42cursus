#include <PhoneBook.hpp>


bool validate_input(std::string input) {
	if (input.empty())
	{
		std::cout << "Invalid input" << std::endl;
		return (false);
	}
	return (true);
}



bool Contact::create_contact()
{
	std::string input;
	std::cout << "Enter first name: ";
	std::getline(std::cin , input);
	if(validate_input(input))
		this->first_name = input;

	std::cout << "Enter last name: ";
	std::getline(std::cin , this->last_name);

	std::cout << "Enter phone_number: ";
	std::getline(std::cin , this->phone_number);

	std::cout << "Enter nickname: ";
 	std::getline(std::cin , this->nickname);

	std::cout << "Enter darkest_secret: ";
	std::getline(std::cin , this->darkest_secret);

	return(true);
}


bool Contact::print_contact()
{
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Phone Number: " << this->phone_number << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Cant tell you thier darkest seceret" << std::endl;
	return (true);
}