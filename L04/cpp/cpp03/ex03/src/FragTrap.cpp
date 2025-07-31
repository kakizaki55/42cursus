#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hit_points = 100;
	this->_engery_points = 100;
	this->_attack_damage = 30;
	this->_high_five_count = 0;
	std::cout << "Default FragTrap constructor called." << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_engery_points = 100;
	this->_attack_damage = 30;
	this->_high_five_count = 0;
	std::cout << "Parameterized FragTrap constructor called: " << _name << " created." << std::endl;
}
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	this->_high_five_count = other._high_five_count;
	std::cout << "Copy FragTrap constructor called: " << _name << " copied." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called: " << _name << " destroyed." << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_high_five_count = other._high_five_count;
	}
	return *this;
}

void FragTrap::highFivesGuys()
{
	if (_hit_points > 0 && _engery_points > 0)
	{
		_high_five_count++;
		std::cout << _name << " requests a high five! High five count: " << _high_five_count << std::endl;
	}
	else
	{
		std::cout << _name << " cannot request a high five!" << std::endl;
	}
}

void FragTrap::get_status()
{
	std::cout << "FragTrap Status: " << _name << "\n"
			  << "Hit Points: " << _hit_points << "\n"
			  << "Energy Points: " << _engery_points << "\n"
			  << "Attack Damage: " << _attack_damage << "\n"
			  << "High Five Count: " << _high_five_count << std::endl;
}