
#include <iostream>
#include <cstring>


int main()
{
	const char *string = "lets cLp thisZZZ0&^##@*^)*&)*\n";
	// int x;
	std::cout << string;
	std::cout << strlen(string)<< "\n";
	// std::cin >> x;
	// std::cout << "you entered: " << x << std::endl;
	// std::transform(string);
	// std::cout << string;
	for(int i = 0; strlen(string) > i; i++)
	{
		// const char c = string[i];
		const char uc = std::toupper(string[i]);
		// putchar(string[i]);
		std::cout << uc << "\n";
	}
	return 0;
}

