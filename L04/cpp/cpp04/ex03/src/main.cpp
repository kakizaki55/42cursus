
#include <iostream>
#include "../include/AMateria.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/MateriaSource.hpp" 
#include "../include/Character.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    me->getName();
    std::cout << std::endl;
    
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->printStatus();
    std::cout << std::endl;

    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("FakeMateria");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->printStatus();
    me->unequip(2);
    me->unequip(3);
    me->unequip(3);
    me->printStatus();
    std::cout << std::endl;

    ICharacter* bob = new Character("bob");

    std::cout << "Using materias on bob: " << std::endl << std::endl;
    bob->printStatus();
    me->use(0, *bob);
    bob->printStatus();
    me->use(1, *bob);
    bob->printStatus();
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    std::cout << std::endl;

    delete src;
    delete me;
    delete bob;

    return EXIT_SUCCESS;
}