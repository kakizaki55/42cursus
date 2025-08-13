#include "../include/Ice.hpp"
#include <iostream>

const unsigned int Ice::damage = 20;

const std::string _type = "ice";

Ice::Ice() : AMateria("ice") {}

Ice::Ice(std::string const &type) : AMateria("ice") 
{
    _type = type;
}

Ice::Ice(const Ice &other) : AMateria(other._type) {}

Ice::~Ice() {}

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
    target.setHitPoints(target.getHitPoints() - this->damage);
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}
