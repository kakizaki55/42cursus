#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_engery_points = 50;
	this->_attack_damage = 20;
	this->_guard_mode = false;
	std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_engery_points = 50;
	this->_attack_damage = 20;
	this->_guard_mode = false;
	std::cout << "Parameterized ScavTrap constructor called: " << _name << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	this->_guard_mode = other._guard_mode;
	std::cout << "Copy ScavTrap constructor called: " << _name << " copied." << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called: " << _name << " destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_guard_mode = other._guard_mode;
	}
	return *this;
}

void ScavTrap::guardGate()
{
	bool guard_mode = this->_guard_mode;
	bool eligibal = (this->_hit_points > 0 && this->_engery_points > 0);
	if (!guard_mode && eligibal)
	{
		this->_guard_mode = true;
		std::cout << _name << " is now in guard mode!" << std::endl;
	}
	else if (guard_mode && eligibal)
	{
		this->_guard_mode = false;
		std::cout << _name << " has exited guard mode!" << std::endl;
	}
	else
	{
		std::cout << _name << " can not switch guard mode..." << std::endl;
	}

}

void ScavTrap:: get_status()
{
	std::cout << "ScavTrap Status: " << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Points: " << this->_hit_points << std::endl;
	std::cout << "Energy Points: " << this->_engery_points << std::endl;
	std::cout << "Attack Damage: " << this->_attack_damage << std::endl;
	std::cout << "Guard Mode: " << (this->_guard_mode ? "Enabled" : "Disabled") << std::endl;
}
