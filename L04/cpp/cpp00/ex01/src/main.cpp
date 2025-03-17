#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{

	PhoneBook phonebook;
	Contact contact;
	contact.create_contact();
	contact.print_contact();
	return (0);
}