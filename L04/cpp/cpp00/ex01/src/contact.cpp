
#include "PhoneBook.hpp"

bool Contact::create_contact()
{
	std::cout << "Enter first name: ";
	std::cin >> this->first_name;

	std::cout << "Enter last name: ";
	std::cin >> this->last_name;

	std::cout << "Enter phone_number: ";
	std::cin >> this->phone_number;

	std::cout << "Enter nickname: ";
	std::cin >> this->nickname;

	std::cout << "Enter darkest_secret: ";
	std::cin >> this->darkest_secret;

	return(true);
}


bool Contact::print_contact()
{
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Phone Number" << this->phone_number << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Cant tell you thier darkest seceret" << std::endl;


	return (true);
}