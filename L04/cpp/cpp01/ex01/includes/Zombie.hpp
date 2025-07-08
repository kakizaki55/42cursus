#include <iostream>
#include <string>
#include <stdlib.h>

#pragma once

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{
	typedef Zombie t;
	
	private:
	
		std::string name;

	public:
		
		Zombie();

		Zombie(std::string name);

		~Zombie();

		void announce();
		void set_name(std::string);

};

Zombie *zombieHorde(int N, std::string name);

#endif