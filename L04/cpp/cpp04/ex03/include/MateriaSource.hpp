#pragma once
#include "./IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _materias[4];
        unsigned int _materiaCount;
        static const unsigned int _max_materia_count;

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        ~MateriaSource();

        MateriaSource &operator=(const MateriaSource &other);

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
        void clearMateria();
};