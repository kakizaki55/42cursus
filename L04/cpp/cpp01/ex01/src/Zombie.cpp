#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = this->get_name();
}

Zombie:: Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " has been destroyed" << std::endl;
}

void Zombie:: announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string  Zombie::get_name(void)
{
	std::string name;
	do{
		std::cout << "Enter the name of the zombie: ";
		std::getline(std::cin, name);
		if (name.empty())
			std::cout << "Name cannot be empty" << std::endl;
	}
	while(name.empty());

	return (name);
}