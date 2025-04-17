
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>

#define	CONTACTS_SIZE 8
#define PHONE_BOOK_WIDTH 10

class Contact
{
	private:

		std::string phone_number;
		std::string darkest_secret;
		std::string last_name;
		std::string nickname;

	public:

		int index;
		std::string first_name;
		Contact()
		{
			this->index = 0;
			this->first_name = "";
			this->last_name = "";
			this->nickname = "";
			this->phone_number = "";
			this->darkest_secret ="";
		}

		bool			create_contact(int index);
		void			index_self(void);
		bool			display_self(void);
		unsigned long 	get_logest(void);
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
		void	index_all_contacts(void);
		void	display_header();

		bool	add(void);
		bool	search(void);
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
bool is_number(const std::string& string);
void truncate_and_print(const std::string& str, unsigned long width);

#endif