#include <iostream>
#include <string>
#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DimondTrap.hpp"

int main()
{
	{
		DimondTrap dimondtrap1("bender");
		dimondtrap1.get_status();
		dimondtrap1.highFivesGuys();
		dimondtrap1.get_status();
		dimondtrap1.takeDamage(10);
		dimondtrap1.get_status();
		dimondtrap1.beRepaired(20);
		dimondtrap1.get_status();
		dimondtrap1.attack("Leela");
		dimondtrap1.highFivesGuys();
		dimondtrap1.get_status();

		DimondTrap dimondtrap2;
		dimondtrap2 = dimondtrap1;
		dimondtrap2.whoAmI();
		return 0;
	}
}
