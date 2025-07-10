


#include <iostream>
#include <string>

#pragma once

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{
	typedef Zombie t;
	public:

		Zombie(std::string name);

		~Zombie();

		void announce();

	private:

		std::string name;

};


Zombie *newZombie(std::string name);

void randomChump(std::string name);

#endif