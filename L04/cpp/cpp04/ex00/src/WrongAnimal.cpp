#include "../include/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("Unknown")
{
	std::cout << "Wrong default Animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << "Copy Animla constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::setType(const std::string &type)
{
	this->type = type;
}

void WrongAnimal::makeSound() const
{
	if(this->type.compare("Unknown") == 0)
	{
		std::cout << "Wrong Animal cant make a sound" << std::endl;
	}
}