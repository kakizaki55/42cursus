#include "../include/Character.hpp"
#include "../include/AMateria.hpp"
#include <iostream>
#include <string>

const unsigned int Character::_max_materia_count = 4;

Character::Character() : _name("default"), _hitPoints(100), _maxHitPoints(100), _materiaCount(0)
{
    for (unsigned int i = 0; i < _max_materia_count; i++)
        _materias[i] = NULL;
}

Character::Character(std::string name) : _name(name), _hitPoints(100), _maxHitPoints(100), _materiaCount(0)
{
    for (unsigned int i = 0; i < _max_materia_count; i++)
        _materias[i] = NULL;
}

Character::Character(const Character &other) : _name(other._name), _hitPoints(other._hitPoints), _maxHitPoints(other._maxHitPoints), _materiaCount(other._materiaCount)
{
    for (unsigned int i = 0; i < _max_materia_count; ++i)
        _materias[i] = other._materias[i] ? other._materias[i]->clone() : NULL;
}

Character::~Character()
{
    clearMateria();
    std::cout << "Character destructor called for " << _name << std::endl;
}
void Character::clearMateria()
{
    for (unsigned int i = 0; i < _max_materia_count; i++)
    {   std::cout << "index is " << i << std::endl;


        // std::cout << "materia found with type" <<_materias[i]->getType() << "index " << i << std::endl;
        if(_materias[i] != NULL)
        {
            delete _materias[i];
            _materias[i] = NULL;
        } 
    }
    _materiaCount = 0;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        clearMateria();
        _name = other._name;
        _hitPoints = other._hitPoints;
        _maxHitPoints = other._maxHitPoints;
        _materiaCount = other._materiaCount;

        for (unsigned int i = 0; i < other._max_materia_count; i++)
        {
            _materias[i] = other._materias[i] ? other._materias[i]->clone() : NULL;
        }
    }
    return *this;
}

std::string const& Character::getName() const
{
    return _name;
}

void Character:: equip(AMateria* m)
{
    for(unsigned int i = 0; i < _max_materia_count; i++)
    {
        if (_materias[i] == NULL)
        {
            _materias[i] = m->clone();
            _materiaCount++;
            std::cout << "Equipped " << m->getType() << " to " << _name << std::endl;
            return;
        }
    }
    std::cout << "Cannot equip " << m->getType() << " to " << _name << ", materia slots full." << std::endl;
}

void Character::unequip(int idx)
{
    if(idx < 0 || idx >= static_cast<int>(_max_materia_count))
    {
        std::cout << "Invalid index for unequip: " << idx << std::endl;
        return;
    }
    if(_materias[idx] == NULL)
    {
        std::cout << "No materia to unequip at index " << idx << std::endl;
        return;
    }
    
    std::cout << "Unequipped " << _materias[idx]->getType() << " from " << _name << std::endl;
    delete _materias[idx];
    _materias[idx] = NULL;
    _materiaCount--;
}

void Character::use(int idx, ICharacter& target)
{
    if(idx < 0 || idx >= static_cast<int>(_max_materia_count))
    {
        std::cout << "Invalid index for use: " << idx << std::endl;
        return;
    }
    if(_materias[idx] == NULL)
    {
        std::cout << "No materia to use at index " << idx << std::endl;
        return;
    }
    _materias[idx]->use(target);
}
