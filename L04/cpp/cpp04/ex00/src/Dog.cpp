#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include <iostream>


Dog::Dog() : Animal()
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->setType("Dog");
}
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Copy Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
