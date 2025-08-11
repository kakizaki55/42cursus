#include <iostream>
#pragma once

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

        std::string const& getType() const; // return materia type
        virtual AMateria* clone() const = 0;
        // virtual void use(ICharactor &target); 
        virtual void use(std::string char_name); //mock function to be implemented in derived classes 
};

