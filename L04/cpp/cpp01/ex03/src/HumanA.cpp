#include "../includes/Human.hpp"

HumanA :: HumanA(std:: string name, Weapon& weapon) : name(name), weapon(weapon)
{
	this->name = name;
	this->weapon = weapon;
	return;
}

HumanA :: ~HumanA()
{
	std::cout <<  "Human " << this->name << " has been distroyed" << std:: endl;
}


void HumanA :: setWeapon(Weapon& weapon)
{
	this->weapon = weapon;
	return;
}

void HumanA :: attack()
{
	std:: cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
	return;
}
