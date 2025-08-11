#include "../include/AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::~AMateria() 
{
    std::cout << "AMateria destructor called on Amateria type: " << _type << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

void AMateria::setType(std::string type) 
{
    this->_type = type;
}

std::string const& AMateria::getType() const
{
    return _type;
}

// Mock function to be implemented in derived classes
void AMateria::use(std::string char_name) 
{
    std::cout << "AMateria used by " << char_name << std::endl;
}