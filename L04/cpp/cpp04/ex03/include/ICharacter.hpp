#pragma once
#include <string>

class AMateria;

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
        virtual void printStatus() = 0;
        virtual unsigned int getHitPoints() const = 0;
        virtual unsigned int getMaxHitPoints() const = 0;
        virtual void setHitPoints(unsigned int hp) = 0;
};

