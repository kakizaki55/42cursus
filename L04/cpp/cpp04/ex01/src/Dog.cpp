#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Brain.hpp"
#include <iostream>


Dog::Dog() : Animal()
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->setType("Dog");
	this->_brain = new Brain();
}
Dog::Dog(const Dog &other) : Animal(other) , _brain(new Brain(*other._brain))
{
	std::cout << "Copy Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
	this->_brain->setIdea(index, idea);
}
std::string Dog::getIdea(int index) const
{
	return this->_brain->getIdea(index);
}
