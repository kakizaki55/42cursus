#include "Human.hpp"
#include "Weapon.hpp"

HumanA :: HumanA(std:: string name, Weapon& weapon) : name(name), weapon(weapon)
{
	this->name = name;
	this->weapon = weapon;
	return;
}

HumanA :: ~HumanA()
{
	this->name = name;
	this->weapon = Weapon();
	return ;
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


// HumanB :: HumanB(std:: string name, Weapon *weapon) : name(name), weapon(weapon)

HumanB :: HumanB(std:: string name) : name(name), weapon(NULL)
{
	this->name = name;
	this->weapon = NULL;
	return;
}

HumanB:: ~HumanB()
{
	// delete this->weapon;
	return ;
}

void HumanB :: setWeapon(Weapon weapon)
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
