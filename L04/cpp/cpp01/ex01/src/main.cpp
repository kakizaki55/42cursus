
#include "Zombie.hpp"

int main() {

    std::cout << "Hello, World!" << std::endl;
    Zombie *zombie = zombieHorde(5, "zombie");

    for(int i = 0; i < 5; i++)
    {
        zombie[i].announce();
    }
    delete [] zombie;
    return EXIT_SUCCESS;
}
