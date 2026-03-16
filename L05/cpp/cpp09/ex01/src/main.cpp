#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: invalid number of arguments." << std::endl;
		return 1;
	}
	
	try {
		RPN rpn;
		long result = rpn.evaluate(argv[1]);
		std::cout << result << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
