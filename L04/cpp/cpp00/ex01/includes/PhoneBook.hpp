
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string.h>
#include <iostream>

#define	CONTACTS_SIZE 8

class Contact
{
	private:
		int index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact()
		{
			this->index = 0;
			this->first_name = "";
			this->last_name = "";
			this->nickname = "";
			this->phone_number = "";
			this->darkest_secret ="";
		}
	bool create_contact(void);
	bool print_contact(void);
};

class PhoneBook
{
	public:
		Contact contacts[CONTACTS_SIZE];
		int contacts_size;
		int add_contact(Contact contact);
		void print_usages(void);
};


#endif