#include <PhoneBook.hpp>

void PhoneBook:: print_usages(void)
{
	std::cout << "Usage: ./phonebook [ADD|SEARCH|EXIT]" << std::endl;
	return;
}

void PhoneBook::index_all_contacts()
{
	this->display_header();
	for (int i = 0; i < this->contacts_size; i++)
	{
		if (this->contacts[i].first_name.empty())
			continue;
		else
			this->contacts[i].index_self();
	}
	return;
}


bool PhoneBook::add()
{
	this->contacts[this->current_index].create_contact(this->current_index);

	if(this->current_index + 1 == this->contacts_size)
		this->current_index = 0;
	else
		this->current_index++;
	return true;
}
bool PhoneBook::search()
{
	std::string input;

	std::cout << "Enter index->";
	std::getline(std::cin, input);

	int index = atoi(input.c_str());

	if(input.empty() || index < 0 || index > this->contacts_size - 1 || is_number(input) == false)
	{
		std::cout << "Invalid index" << std::endl;
		return false;
	}

	if(this->contacts[index].first_name.empty())
	{
		std::cout << "No contact found" << std::endl;
		return false;
	}

	this->contacts[index].display_self();
	return (true);
}


void PhoneBook::display_header()
{
	const int width = PHONE_BOOK_WIDTH;
	std::cout << std::setw(width) << std::right << "Index" << "|";
	std::cout << std::setw(width) << std::right << "First Name" << "|";
	std::cout << std::setw(width) << std::right << "Last Name" << "|";
	std::cout << std::setw(width) << std::right << "Nickname" << "|" << std::endl;
	return;

}


