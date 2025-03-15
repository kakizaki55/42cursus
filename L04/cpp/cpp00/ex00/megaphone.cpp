
#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{

	if (argc < 2) {
		std::cout << "* LOUD NOISE *";
	} else {
		std:: cout << "you have more then one argument";
	}
	std::cout << std::endl;
	return 0;
}