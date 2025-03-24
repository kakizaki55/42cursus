#include <PhoneBook.hpp>

void PhoneBook:: print_usages(void)
{
	std::cout << "Usage: ./phonebook [add|search|exit]" << std::endl;
	return;
}

// void PhoneBook::display_contact()
// {

// 	return;
// }
void PhoneBook::display_all_contacts()
{
	for (size_t i = 0; i < this->contacts_size; i++)
	{
		if (this->contacts[i].first_name.empty())
			continue;
		else
			this->contacts[i].print_contact();
	}
	return;
}
bool PhoneBook::add()
{
	std::cout << "index:" << this->current_index << std::endl;
	this->contacts[this->current_index].create_contact(this->current_index);

	if(this->current_index == this->contacts_size)
		this->current_index = 0;
	else
		this->current_index++;
	return true;
}
int PhoneBook::search_contact(int index)
{
	return (0);
}


