#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include <iostream>


Cat::Cat() : Animal()
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->setType("Cat");
}
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}