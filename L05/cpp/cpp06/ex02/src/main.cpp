#include "../include/Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	// Test 1: Generate random instances and identify them
	std::cout << "--- Test 1: Generate and identify using pointer ---" << std::endl;
	for (int i = 0; i < 5; i++) {
		Base* ptr = generate();
		std::cout << "Generated object " << i + 1 << ": ";
		identify(ptr);
		delete ptr;
	}
	std::cout << std::endl;

	// Test 2: Create specific instances and identify using pointer
	std::cout << "--- Test 2: Identify specific instances (pointer) ---" << std::endl;
	Base* a = new A();
	Base* b = new B();
	Base* c = new C();

	std::cout << "A instance: ";
	identify(a);
	std::cout << "B instance: ";
	identify(b);
	std::cout << "C instance: ";
	identify(c);
	std::cout << std::endl;

	// Test 3: Identify using reference
	std::cout << "--- Test 3: Identify specific instances (reference) ---" << std::endl;
	std::cout << "A instance: ";
	identify(*a);
	std::cout << "B instance: ";
	identify(*b);
	std::cout << "C instance: ";
	identify(*c);
	std::cout << std::endl;

	// Test 4: Compare pointer vs reference identification
	std::cout << "--- Test 4: Pointer vs Reference comparison ---" << std::endl;
	Base* random = generate();
	std::cout << "Same object identified by pointer: ";
	identify(random);
	std::cout << "Same object identified by reference: ";
	identify(*random);
	std::cout << std::endl;

	// Cleanup
	delete a;
	delete b;
	delete c;
	delete random;
	return 0;
}
