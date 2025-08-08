#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
		std::cout << std::endl;
	}

	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the wonrg cat sound!
		meta->makeSound();
		delete meta;
		delete i;
		std::cout << std::endl;
	}

	Animal *animal = new Animal();
	animal->makeSound();
	delete animal;
	std::cout << std::endl;

	Animal *cat = new Cat();
	cat->makeSound();
	delete cat;
	std::cout << std::endl;

	Animal *dog = new Dog();
	dog->makeSound();
	delete dog;
	std::cout << std::endl;
	return EXIT_SUCCESS;
}