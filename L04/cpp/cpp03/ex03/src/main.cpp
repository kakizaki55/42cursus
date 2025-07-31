#include <iostream>
#include <string>
#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main()
{
	// {
	// 	ScavTrap scavtrap1("bender");
	// 	scavtrap1.get_status();
	// 	scavtrap1.guardGate();
	// 	scavtrap1.get_status();
	// 	scavtrap1.takeDamage(5);
	// 	scavtrap1.get_status();
	// 	scavtrap1.beRepaired(10);
	// 	scavtrap1.get_status();
	// 	scavtrap1.attack("Fry");
	// 	return 0;
	// }
	{
		FragTrap fragtrap1("fry");
		fragtrap1.get_status();
		fragtrap1.highFivesGuys();
		fragtrap1.get_status();
		fragtrap1.takeDamage(10);
		fragtrap1.get_status();
		fragtrap1.beRepaired(20);
		fragtrap1.get_status();
		fragtrap1.attack("Leela");
		fragtrap1.highFivesGuys();
		fragtrap1.get_status();
		return 0;
	}
}
