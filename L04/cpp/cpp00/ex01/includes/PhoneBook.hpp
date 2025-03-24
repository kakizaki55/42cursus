
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string.h>
#include <iostream>

#define	CONTACTS_SIZE 8

class Contact
{
	private:

		std::string phone_number;
		std::string darkest_secret;

	public:

		int index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		Contact()
		{
			this->index = 0;
			this->first_name = "";
			this->last_name = "";
			this->nickname = "";
			this->phone_number = "";
			this->darkest_secret ="";
		}

		bool	create_contact(int index);
		void	display_contact(void);
};

class PhoneBook
{
	private:

		int current_index;
		int previous_index;
		int contacts_size;

	public:

		Contact contacts[CONTACTS_SIZE];
		PhoneBook()
		{
			this->current_index = 0;
			this->previous_index = 0;
			this->contacts_size = CONTACTS_SIZE;
		}

		void	print_usages(void);
		// void	display_contact();
		void	display_all_contacts();
		bool	add(void);
		int		search_contact(int index);
};

enum Command
{
	ADD,
	SEARCH,
	EXIT,
	INVALID
};

enum ContactFields
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET
};


Command get_command(const std::string& command);

#endif