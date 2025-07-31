#include "./ClapTrap.hpp"
#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"
#pragma once


class DimondTrap : virtual public FragTrap, virtual public ScavTrap
{
	private:
		// unsigned int _diamond_hit_points;
		// unsigned int _diamond_max_hit_points;
		// unsigned int _diamond_engery_points;
		// unsigned int _diamond_attack_damage;

	public:
		DimondTrap();
		DimondTrap(std::string name);
		DimondTrap(const DimondTrap &other);
		~DimondTrap();

		DimondTrap &operator=(const DimondTrap &other);

		// void attack(const std::string& target);
		void get_status();
};