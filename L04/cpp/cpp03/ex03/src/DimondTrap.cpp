#include "../include/DimondTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"


DimondTrap::DimondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	this->_name = "default_dimond_trap";
	this->ClapTrap::_name = this->_name + "_clap_trap";
	this->_hit_points = FragTrap::_hit_points;
	this->_max_hit_points = FragTrap::_max_hit_points;
	this->_engery_points = ScavTrap::_engery_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << "Default DimondTrap constructor called." << std::endl;
}

DimondTrap::DimondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_trap";
	this->_hit_points = FragTrap::_hit_points;
	this->_max_hit_points = FragTrap::_max_hit_points;
	this->_engery_points = ScavTrap::_engery_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << "Parameterized DimondTrap constructor called: " << _name << " created." << std::endl;
}
DimondTrap::DimondTrap(const DimondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	this->_name = other._name;
	this->ClapTrap:: _name = other._name + "_clap_trap";
	this->_hit_points = other._hit_points;
	this->_max_hit_points = other._max_hit_points;
	this->_engery_points = other._engery_points;
	this->_attack_damage = other._attack_damage;
	std::cout << "Copy DimondTrap constructor called: " << _name << " copied." << std::endl;
}

DimondTrap::~DimondTrap()
{
	std::cout << "DimondTrap destructor called: " << _name << " destroyed." << std::endl;
}
DimondTrap &DimondTrap::operator=(const DimondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		this->_name = other._name;
		this->ClapTrap::_name = other._name + "_clap_trap";
		this->_hit_points = other._hit_points;
		this->_max_hit_points = other._max_hit_points;
		this->_engery_points = other._engery_points;
		this->_attack_damage = other._attack_damage;
	}
	return *this;
}

void DimondTrap::whoAmI()
{
	std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

void DimondTrap::get_status()
{
	std::cout 	<< "DimondTrap Status: " << std::endl
				<< "Name: " << _name << std::endl
				<< "ClapTrap Name: " << ClapTrap::_name << std::endl
				<< "Hit Points: " << _hit_points << std::endl
				<< "Max Hit Points: " << _max_hit_points << std::endl
				<< "Energy Points: " << _engery_points << std::endl
				<< "Attack Damage: " << _attack_damage << std::endl;
}
