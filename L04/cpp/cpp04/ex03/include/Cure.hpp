#include "../include/AMateria.hpp"
#pragma once
#include <string>

class Cure : public AMateria
{
    private:
        // std::string _type = "Cure";
    public:
        Cure();
        Cure(std::string const &type);
        Cure(const Cure &other);
        ~Cure();

        Cure &operator=(const Cure &other);
        AMateria* clone() const;
        void use(std::string char_name);// Implement the use function for Cure
};