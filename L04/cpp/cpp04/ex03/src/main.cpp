
#include <iostream>
#include "../include/AMateria.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/MateriaSource.hpp" 
#include "../include/Character.hpp"

int main()
{
    //AMatria pure abstract class/ interface for matiria
    //nees make a class for Ice and Cure using AMatria 

    // Matreria Source useres another interface thats is called IMatriaSource

    // needs a charater interface to make a charter class
    // needs a character class that can use up to 4 matria (not unique)
    
    // AMateria *ice = new AMateria("ice");
    // ice->use("Character1");
    // AMateria *iceClone = ice->clone();
    // iceClone->use("Character2");

    // AMateria *cure = new Cure("cure");
    // cure->use("Character1");
    // AMateria *cureClone = cure->clone();
    // cureClone->use("Character2");   

    // delete ice;
    // delete iceClone;
    // delete cure;
    // delete cureClone;
    // ice->use("Character1");

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    

    ICharacter* me = new Character("me");

    AMateria* tmp;

    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete tmp;
    delete src;
    delete me;
    delete bob;

    return 0;
}