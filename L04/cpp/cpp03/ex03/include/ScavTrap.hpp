#include "../include/ClapTrap.hpp"
#include <iostream>
#pragma once

class ScavTrap : virtual public ClapTrap
{
	protected:
		bool _guard_mode;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap &other);

		void guardGate();
		void get_status();
};