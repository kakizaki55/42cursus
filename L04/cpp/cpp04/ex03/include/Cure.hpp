#pragma once
#include "../include/AMateria.hpp"
#include <string>

class ICharacter;
class Cure : public AMateria
{
    private:
        static const unsigned int healingPower;
    public:
        Cure();
        Cure(std::string const &type);
        Cure(const Cure &other);
        ~Cure();

        Cure &operator=(const Cure &other);
        AMateria* clone() const;
        void use(ICharacter &target);
};