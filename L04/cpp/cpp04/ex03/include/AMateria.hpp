#pragma once
#include <iostream>
#include "../include/ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
        void setType(std::string type);

    public:
        AMateria();
        AMateria(std::string const &type);
        virtual ~AMateria();

        AMateria &operator=(const AMateria &other);

        std::string const& getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter &target); 
};

