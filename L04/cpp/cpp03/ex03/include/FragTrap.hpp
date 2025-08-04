#include "../include/ClapTrap.hpp"
#pragma once


class FragTrap : public virtual ClapTrap
{
	protected:
		unsigned int _high_five_count;

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap();

		FragTrap &operator=(const FragTrap &other);

		void highFivesGuys();
		void get_status();
};
