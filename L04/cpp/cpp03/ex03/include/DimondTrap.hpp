#include "./ClapTrap.hpp"
#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"
#pragma once


class DimondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;

	public:
		DimondTrap();
		DimondTrap(std::string name);
		DimondTrap(const DimondTrap &other);
		~DimondTrap();

		DimondTrap &operator=(const DimondTrap &other);\

		using ScavTrap::attack; 
		void whoAmI();
		void get_status();
};