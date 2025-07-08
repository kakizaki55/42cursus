#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{	
	int number_or_zombies = N;
	int i = 0;
	Zombie *zombie = new Zombie[number_or_zombies];
	while(i < number_or_zombies)
	{
		zombie[i].set_name(name);
		i++;
	}
	return (zombie);
}