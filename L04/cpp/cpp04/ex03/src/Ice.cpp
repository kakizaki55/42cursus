#include "../include/Ice.hpp"
#include <iostream>

const std::string _type = "ice";

Ice::Ice() : AMateria("ice") {}

Ice::Ice(std::string const &type) : AMateria("ice") 
{
    _type = type;
}

Ice::Ice(const Ice &other) : AMateria(other._type) {}

Ice::~Ice() 
{
    std::cout << "Ice destructor called on Ice type: " << _type << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

AMateria* Ice::clone() const 
{
    return new Ice(*this);
}


void Ice::use(ICharacter &target) 
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}