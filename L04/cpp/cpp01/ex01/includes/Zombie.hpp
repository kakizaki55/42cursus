#include <iostream>
#include <string>
#include <stdlib.h>

#pragma once

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{
	typedef Zombie t;
	public:

		Zombie();

		Zombie(std::string name);

		~Zombie();

		void announce();
		std::string get_name(void);

	private:

		std::string name;

};

Zombie *zombieHorde(int N, std::string name);

#endif