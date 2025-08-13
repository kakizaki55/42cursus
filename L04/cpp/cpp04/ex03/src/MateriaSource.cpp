#include "../include/MateriaSource.hpp"

const unsigned int MateriaSource::_max_materia_count = 4;

MateriaSource::MateriaSource() : _materiaCount(0)
{
    for (unsigned int i = 0; i < _max_materia_count; ++i)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) : _materiaCount(other._materiaCount)
{
    for (unsigned int i = 0; i < _max_materia_count; ++i)
        _materias[i] = other._materias[i] ? other._materias[i]->clone() : NULL;
}

MateriaSource::~MateriaSource()
{
    
    clearMateria();
    std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        clearMateria();
        _materiaCount = other._materiaCount;
        for (unsigned int i = 0; i < _max_materia_count; ++i)
        {
            _materias[i] = other._materias[i] ? other._materias[i]->clone() : NULL;
        }
    }
    return *this;
}

void MateriaSource::clearMateria()
{
    for (unsigned int i = 0; i < _max_materia_count; i++)
    {
        if (_materias[i])
        {
            delete _materias[i];
            _materias[i] = NULL;
        }
    }
    _materiaCount = 0;
}


void MateriaSource::learnMateria(AMateria* m)
{
    if (_materiaCount < _max_materia_count && m)
    {
        for (unsigned int i = 0; i < _max_materia_count; i++)
        {
            if (!_materias[i])
            {   
                _materias[i] = m;
                ++_materiaCount;
                std::cout << "Learned materia: " << m->getType() << std::endl;
                return;
            }
        }
    }
    if(m)
        delete m; 
    std::cout << "MateriaSource is full or invalid materia" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (unsigned int i = 0; i < _max_materia_count; i++)
    {

        if (_materias[i] && _materias[i]->getType() == type)
        {
            std::cout << "Creating materia: " << type << std::endl;
            return _materias[i]->clone();
        }
    }
    std::cout << "Materia of type " << type << " not found" << std::endl;
    return NULL;
}
