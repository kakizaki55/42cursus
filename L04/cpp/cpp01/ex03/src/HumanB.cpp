#include "Human.hpp"
#include "Weapon.hpp"

HumanB :: HumanB(std:: string name) : name(name), weapon(NULL)
{
	this->name = name;
	this->weapon = NULL;
	return;
}

HumanB:: ~HumanB()
{
	std::cout <<  "Human " << this->name << " has been distroyed" << std:: endl;
}

void HumanB :: setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	return;
}


void HumanB :: attack(void)
{
	if(this->weapon == NULL)
	{
		std:: cout << this->name << " has no weapon to attack with" << std::endl;
		return ;
	}
	std:: cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	return;
}
