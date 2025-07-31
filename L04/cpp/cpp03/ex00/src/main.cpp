#include <iostream>
#include "../include/ClapTrap.hpp"


int main()
{
	ClapTrap claptrap("ROBOT");
	claptrap.get_status();
	claptrap.attack("ANOTHER ROBOT");
	claptrap.takeDamage(5);
	claptrap.get_status();
	claptrap.beRepaired(3);
	claptrap.attack("Bender");
	claptrap.takeDamage(10);
	claptrap.get_status();
}