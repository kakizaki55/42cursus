#include <iostream>
#include <string>
#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main()
{
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
