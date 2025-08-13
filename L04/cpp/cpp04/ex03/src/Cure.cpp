#include "../include/Cure.hpp"
#include <iostream> 

const std::string _type = "cure";
const unsigned int Cure::healingPower = 30;

Cure::Cure() : AMateria("cure") {}

Cure::Cure(std::string const &type) : AMateria("cure") 
{
    _type = type;
}

Cure::Cure(const Cure &other) : AMateria(other._type) {}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
    {
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
    target.getMaxHitPoints();
    if (target.getHitPoints() + this->healingPower > target.getMaxHitPoints())
        target.setHitPoints(target.getMaxHitPoints());
    else
        target.setHitPoints(target.getHitPoints() + this->healingPower);
    std::cout << "* heals " << target.getName() << "'s wounds *"<< std::endl;
}
