#include "../include/Ice.hpp"
#include "../include/AMateria.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(std::string const &type) : AMateria("ice") 
{
    (void)type; // type is not used in this implementation
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

void Ice::use(std::string char_name) 
{
    std::cout << "* shoots an ice bolt at " << char_name << " *"<< std::endl;
}