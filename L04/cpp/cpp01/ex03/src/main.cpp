#include "Weapon.hpp"
#include "Human.hpp"
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;

    {
        // std::cout << "club type: " << club.getType() << std::endl;
        // club.setType("some other type of club");
        // std::cout << "club type: " << club.getType() << std::endl;

        Weapon club = Weapon("crude spiked club");
        Weapon sword = Weapon("long sword");

        HumanA bob("Bob", club);

        // bob.setWeapon(club);
        bob.attack();


        club.setType("ball and chain");
        // std::cout << "club type: " << club.getType() << std::endl;
        bob.attack();
        // club.setType("some other type of club");
        // bob.setWeapon(sword);
        // bob.attack();
    }



    {
        Weapon sword = Weapon("long sword");

        HumanB jim("Jim");

        // jim.setWeapon(&club);
        jim.attack();
        jim.setWeapon(sword);
        jim.attack();

        sword.setType("short sword");
        // std::cout << "club type: " << club.getType() << std::endl;
        jim.attack();
        // club.setType("some other type of club");
        // jim.setWeapon(&sword);
        // jim.attack();
    }

    return 0;



}

