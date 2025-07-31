#include "../include/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: _name("Default"), _hit_points(10), _engery_points(10), _attack_damage(0)
	{
		std::cout << "Default constructor called:" << _name << " created." << std::endl;
	}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hit_points(10), _engery_points(10), _attack_damage(0)
	{
		std::cout << "Parameterized constructor called: " << _name << " created." << std::endl;
	}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hit_points(other._hit_points),
	  _engery_points(other._engery_points), _attack_damage(other._attack_damage)
	{
		std::cout << "Copy constructor called: " << _name << " copied." << std::endl;
	}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called: " << _name << " destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hit_points = other._hit_points;
		_engery_points = other._engery_points;
		_attack_damage = other._attack_damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (_engery_points > 0 && _hit_points > 0)
	{
		std::cout << _name << " attacks " << target
				  << ", causing " << _attack_damage << " points of damage!" << std::endl;
		_engery_points--;
	}
	else
	{
		std::cout << _name << " cannot attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _hit_points)
	{
		_hit_points = 0;
		std::cout << _name << " has been destroyed!" << std::endl;
	}
	else
	{		_hit_points -= amount;
		std::cout << _name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_engery_points > 0 && _hit_points > 0)
	{
		_hit_points += amount;
		_engery_points--;
		std::cout << _name << " repairs itself for " << amount << " points!" << std::endl;
	}
	else
	{
		std::cout << _name << " cannot be repaired!" << std::endl;
	}
}

void ClapTrap::get_status()
{
	std::cout << "ClapTrap " << _name << " Status:" << std::endl;
	std::cout << "Hit Points: " << _hit_points << std::endl;
	std::cout << "Energy Points: " << _engery_points << std::endl;
	std::cout << "Attack Damage: " << _attack_damage << std::endl;
}