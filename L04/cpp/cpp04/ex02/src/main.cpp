#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/Brain.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
	// Uncomment to check to see if animal is an abstract class
	// Animal animal = new Animal();
	Cat *cat1 = new Cat();

	cat1->makeSound();
	return EXIT_SUCCESS;
}