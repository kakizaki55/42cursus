#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cout << "Error: not enough args" << std::endl;
		return 1;
	}

	try {
		PmergeMe pm;
		pm.parseArgs(argc, argv);
		pm.printBefore();
		pm.sort();
		pm.printAfter();

		std::cout << "Time to process a range of " << pm.size()
		          << " elements with std::vector : "
		          << pm.timeVec() << " us" << std::endl;

		std::cout << "Time to process a range of " << pm.size()
		          << " elements with std::deque  : "
		          << pm.timeDeq() << " us" << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}