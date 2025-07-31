#include "../include/DimondTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"


DimondTrap::DimondTrap() : ClapTrap("default ClapTrap")
{
	this->_name = "Default DimondTrap";
	this->_hit_points = FragTrap::_hit_points;
	this->_max_hit_points = FragTrap::_max_hit_points;
	this->_engery_points = ScavTrap::_engery_points;
	this->_attack_damage = FragTrap::_attack_damage;
	// this needs to have the attack from Scavtrap??
	std::cout << "Default DimondTrap constructor called." << std::endl;
}
{
	this->_name = "Default DimondTrap";
	ClapTrap::_name = "Default ClapTrap";
	this->_hit_points = FragTrap::_hit_points;
	this->_max_hit_points = FragTrap::_max_hit_points;
	this->_engery_points = ScavTrap::_engery_points;
	this->_attack_damage = FragTrap::_attack_damage;
	// this needs to have teh attack from Scavtrap???
	std::cout << "Default DimondTrap constructor called." << std::endl;
}

// DimondTrap::DimondTrap(std::string name) : FragTrap(name), ScavTrap(name)
// {
// 	this->_name = name;
// 	ClapTrap::_name = name;
// 	std::cout << "Parameterized DimondTrap constructor called: " << _name << " created." << std::endl;
// }

// DimondTrap::DimondTrap(const DimondTrap &other) : FragTrap(other), ScavTrap(other)
// {
// 	this->_name = other._name;
// 	ClapTrap::_name = other._name;
// 	std::cout << "Copy DimondTrap constructor called: " << _name << " copied." << std::endl;
// }

// DimondTrap::~DimondTrap()
// {
// 	std::cout << "DimondTrap destructor called: " << _name << " destroyed." << std::endl;
// }

// DimondTrap &DimondTrap::operator=(const DimondTrap &other)
// {
// 	if (this != &other)
// 	{
// 		FragTrap::operator=(other);
// 		ScavTrap::operator=(other);
// 		this->_name = other._name;
// 		ClapTrap::_name = other._name;
// 	}
// 	return *this;
// }