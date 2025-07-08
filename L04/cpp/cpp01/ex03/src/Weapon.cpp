#include "Weapon.hpp"

const std::string& Weapon::getType()
{
	std:: string& typeREF = this->type;
	return typeREF;

}
void Weapon::setType(std:: string type)
{
	this->type = type;
}

Weapon :: Weapon(std:: string type)
{
	this->type = type;
}
Weapon ::Weapon ()
{
	this->type = "default";
}

Weapon :: ~Weapon()
{
	return;
}
