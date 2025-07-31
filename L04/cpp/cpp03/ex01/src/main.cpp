#include <iostream>
#include <string>
#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
int main()
{
	ScavTrap scavtrap1("bender");
	scavtrap1.get_status();
	scavtrap1.guardGate();
	scavtrap1.get_status();
	scavtrap1.takeDamage(5);
	scavtrap1.get_status();
	scavtrap1.beRepaired(10);
	scavtrap1.get_status();
	scavtrap1.attack("Fry");
	return 0;
}
