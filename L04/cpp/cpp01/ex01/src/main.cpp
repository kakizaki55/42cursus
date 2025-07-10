
#include "../include/Zombie.hpp"

int main() {

    int nbr = 20;
    Zombie *zombie = zombieHorde(nbr, "bobby");

    for(int i = 0; i < nbr; i++)
    {
        zombie[i].announce();
    }

    delete [] zombie;
    return EXIT_SUCCESS;
}

