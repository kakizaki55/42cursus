#include "../include/Cure.hpp"
#include <iostream> 

Cure::Cure() : AMateria("cure") {}

Cure::Cure(std::string const &type) : AMateria("cure") 
{
    (void)type; // type is not used in this implementation
}

Cure::Cure(const Cure &other) : AMateria(other._type) {}

Cure::~Cure() 
{
    std::cout << "Cure destructor called on Cure type: " << _type << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

AMateria* Cure::clone() const 
{
    return new Cure(*this);
}

void Cure::use(std::string char_name) 
{
    std::cout << "* heals " << char_name << "'s wounds *"<< std::endl;
}