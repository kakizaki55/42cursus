#include <PhoneBook.hpp>

bool validate_input(std::string input) {
	if (input.empty())
	{
		std::cout << "Invalid input, try again" << std::endl;
		return (false);
	}
	return (true);
}

bool Contact::create_contact(int index)
{
	std::string input;

	this->index = index;

	do {
		std::cout << "Enter first name: ";
		std::getline(std::cin , input);
		if(validate_input(input))
			this->first_name = input;
	} while (this->first_name.empty());

	do {
		std::cout << "Enter last name: ";
		std::getline(std::cin , input);
		if(validate_input(input))
			this->last_name = input;
	} while (this->last_name.empty());

	do {
		std::cout << "Enter phone_number: ";
		std::getline(std::cin , input);
		if(validate_input(input))
			this->phone_number = input;
	} while (this->phone_number.empty());

	do {
		std::cout << "Enter nickname: ";
		std::getline(std::cin , input);
		if(validate_input(input))
			this->nickname = input;
	} while (this->nickname.empty());

	do {
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin , input);
		if(validate_input(input))
			this->darkest_secret = input;
	} while (this->darkest_secret.empty());

	return(true);
}


void Contact::index_self()
{
	const int width = PHONE_BOOK_WIDTH;
	std::cout << std::setw(width) << std::right << this->index << "|";
	truncate_and_print(this->first_name, width);
	truncate_and_print(this->last_name, width);
	truncate_and_print(this->nickname, width);
	std:: cout << std::endl;
}


bool Contact::display_self()
{
	std::cout << "Contact Details:" << std::endl;
	truncate_and_print(this->first_name, this->first_name.length() + 1);
	truncate_and_print(this->last_name, this->last_name.length() + 1);
	truncate_and_print(this->nickname, this->nickname.length() + 1 );
	truncate_and_print(this->phone_number, this->phone_number.length()+ 1);
	std::cout << std::endl;
	return(true);
}

int Contact::get_logest()
{
	int max_length = this->first_name.length();

	if (this->last_name.length() > max_length)
		max_length = this->last_name.length();

	if (this->nickname.length() > max_length)
		max_length = this->nickname.length();

	if (this->phone_number.length() > max_length)
		max_length = this->phone_number.length();

	if (this->darkest_secret.length() > max_length)
		max_length = this->darkest_secret.length();

	return (max_length);
}
