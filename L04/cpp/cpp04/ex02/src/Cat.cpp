#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include <iostream>


Cat::Cat() : Animal()
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->setType("Cat");
	this->_brain = new Brain();
}
Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
	this->_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return this->_brain->getIdea(index);
}