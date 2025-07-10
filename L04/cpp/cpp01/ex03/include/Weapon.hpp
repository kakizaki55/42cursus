#include <iostream>

#pragma once

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
	private:
		std::string type;

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		const std::string& getType();
		void setType(std:: string);
};


#endif