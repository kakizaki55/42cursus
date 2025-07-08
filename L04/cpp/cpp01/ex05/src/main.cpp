#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error must have level : " << argv[0] << " <level>" << std::endl;
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

