#pragma once
#include "./ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _maxHitPoints;
        unsigned int _materiaCount;
        static const unsigned int _max_materia_count;
        AMateria *_materias[4];

    public:
        Character();
        Character(std::string name);
        Character(const Character &other);
        ~Character();

        Character &operator=(const Character &other);

        void clearMateria();
        std::string const& getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};
