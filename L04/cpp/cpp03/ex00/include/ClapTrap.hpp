#include <iostream>
#include <string>
#pragma once

class ClapTrap
{
	private:
		std::string  _name;
		unsigned int _hit_points;
		unsigned int _max_hit_points;
		unsigned int _engery_points;
		unsigned int _attack_damage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap &other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void get_status();
};
