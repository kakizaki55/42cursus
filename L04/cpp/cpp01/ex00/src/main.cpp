#include "../includes/Zombie.hpp"
#include <stdlib.h>
int main(void)
{
	Zombie *zombie_a = new Zombie("ken");
	zombie_a->announce();
	delete zombie_a;

	Zombie *zombie_b = newZombie("barbie");
	delete zombie_b;

	randomChump("chucky");

	return (EXIT_SUCCESS);
}