#include <string>
#include "../include/AMateria.hpp"
#pragma once


class Ice : public AMateria
{
    private:
        // std::string _type = "ice";
        // int damage;
    public:
        Ice();
        Ice(std::string const &type);
        Ice(const Ice &other);
        ~Ice();

        Ice &operator=(const Ice &other);
        AMateria* clone() const;
        void use(std::string char_name);// Implement the use function for Ice
};