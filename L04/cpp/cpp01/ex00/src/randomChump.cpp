// this is a function that creates a new instance of a zombie and doesnt return it.

#include "Zombie.hpp"


void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}