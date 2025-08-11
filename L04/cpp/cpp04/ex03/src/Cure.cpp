#include "../include/Cure.hpp"
#include <iostream> 

const std::string _type = "cure";

Cure::Cure() : AMateria("cure") {}

Cure::Cure(std::string const &type) : AMateria("cure") 
{
    _type = type;
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

void Cure::use(ICharacter &target) 
{
    std::cout << "* heals " << target.getName() << "'s wounds *"<< std::endl;
}