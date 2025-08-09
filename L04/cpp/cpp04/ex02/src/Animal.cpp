#include "../include/Animal.hpp"
#include <iostream>

Animal::Animal() : type("Unknown")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Copy Animla constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::setType(const std::string &type)
{
	this->type = type;
}
