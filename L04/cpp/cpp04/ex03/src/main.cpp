


int main()
{
    //AMatria pure abstract class/ interface for matiria
    //nees make a class for Ice and Cure using AMatria 

    // Matreria Source useres another interface thats is called IMatriaSource

    // needs a charater interface to make a charter class
    // needs a character class that can use up to 4 matria (not unique)

    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}