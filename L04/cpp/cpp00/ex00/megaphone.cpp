#include <iostream>
#include <cstring>
#include <string>


int main(int argc, char **argv)
{
	std::string res = "";

	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {
		for (int i = 1; i < argc; i++)
		{
			std::string temp = argv[i];
			for (size_t j = 0; j < temp.length(); j++)
				temp[j] = std::toupper(temp[j]);
			res += temp;
		}
		std::cout << res;
	}
	std::cout << std::endl;
	return 0;
}