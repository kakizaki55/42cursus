#include <PhoneBook.hpp>

void PhoneBook:: print_usages(void)
{
	std::cout << "Usage: ./phonebook [ADD|SEARCH|EXIT]" << std::endl;
	return;
}

void PhoneBook::index_all_contacts()
{
	for (size_t i = 0; i < this->contacts_size; i++)
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
	std::cout << "index:" << this->current_index << std::endl;
	std::cout << "contact size:" << this->contacts_size << std::endl;

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
	if(input.empty() || index < 0 || index > this->contacts_size)
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


