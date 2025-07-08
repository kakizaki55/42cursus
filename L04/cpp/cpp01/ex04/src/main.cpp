#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    if(argc != 4)
    {
        std::cerr << "Error: must have 3 args: " << argv[0] << " <file_name> <str1> <str2>" << std::endl;
        return 1;
    }

    std::string file_name = argv[1];
    std::string str1 = argv[2];
    std::string str2 = argv[3];
    std::string replace  = ".replace";

    if(file_name.empty() || str1.empty() || str2.empty())
    {
        std::cerr << "Error: All arguments must be non-empty." << std::endl;
        return 1;
    }

    std::ifstream input_file(file_name.c_str());
    if (!input_file.is_open()) {
        std::cerr << "Error opening file: " << file_name << std::endl;
        return 1;
    }

    std::ofstream output_file(file_name.append(".replace").c_str());
    if (!output_file.is_open()) {
        std::cerr << "Error opening output file: output.txt" << std::endl;
        if(input_file.is_open())
            input_file.close();
        return 1;
    }

    std:: string line;

    while(getline(input_file, line))
    {
        int index = 0;
        index = line.find(str1);
        while((index = line.find(str1)) != -1)
        {
            line.erase(index, str1.length());
            line.insert(index, str2);
            index += line.length();
        }

        output_file << line << std:: endl;
    }

    return 0;
}

