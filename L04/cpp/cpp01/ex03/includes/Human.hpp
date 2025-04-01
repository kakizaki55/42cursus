
#include <iostream>
#include "Weapon.hpp"

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA
{
	private:

		std:: string name;
		Weapon& weapon;

	public:

		HumanA(std:: string name, Weapon& weapon);
		~HumanA();
		void setWeapon(Weapon& weapon);
		void attack(void);
};

class HumanB
{
	private:

		std:: string name;
		Weapon *weapon;

	public:

		HumanB(std:: string name);
		~HumanB();
		void setWeapon(Weapon weapon);
		void attack(void);
};




#endif