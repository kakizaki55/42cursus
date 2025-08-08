#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include <iostream>


WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "Default WrongCat constructor called" << std::endl;
	this->setType("WrongCat");
}
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "Copy wrong Cat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}