
#include <cstdio>

#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: need to add a <level>." << std::endl;
        return 1;
    }

    std::string level = argv[1];
    if (level.empty())
    {
        std::cerr << "Error: Level cannot be empty." << std::endl;
        return 1;
    }

    Harl harl;
    harl.complain(level);

    return 0;
}

