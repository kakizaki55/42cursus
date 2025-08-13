#pragma once
#include "../include/AMateria.hpp"
#include <string>

class ICharacter;
class Ice : public AMateria
{
    private:
        static const unsigned int damage;

    public:
        Ice();
        Ice(std::string const &type);
        Ice(const Ice &other);
        ~Ice();

        Ice &operator=(const Ice &other);
        AMateria* clone() const;

        void use(ICharacter &target);
};