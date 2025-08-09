#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/Brain.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
	{
		//CAT test
		Cat *cat1 = new Cat();
		cat1->makeSound();
		cat1->setIdea(0, "lets knocks some things over");
		std::cout << "Cat's first idea: " << cat1->getIdea(0) << std::endl;
		std::cout << "Cat's second idea: " << cat1->getIdea(1) << std::endl;
		cat1->setIdea(1, "I own this place now");
		std::cout << "Cat's second idea: " << cat1->getIdea(1) << std::endl;
		std::cout << std::endl;

		//Testing Assimnet operator
		Cat *cat2 = new Cat();
		*cat2 = *cat1;
		std::cout << "Cat's first idea: " << cat2->getIdea(0) << std::endl;
		std::cout << "Cat's second idea: " << cat2->getIdea(1) << std::endl;
		std::cout << std::endl;

		//Testing copy constuctor
		Cat *cat3 = new Cat(*cat1);
		std::cout << "Cat's first idea: " << cat3->getIdea(0) << std::endl;
		std::cout << "Cat's second idea: " << cat3->getIdea(1) << std::endl;
		std::cout << std::endl;

		delete cat1;
		delete cat2;
		delete cat3;
		std::cout << std::endl;
	}
	{
		//Dog test
		Dog *dog1 = new Dog();
		dog1->makeSound();
		dog1->setIdea(0, "food, doof, foo food...");
		std::cout << "Dog's first idea: " << dog1->getIdea(0) << std::endl;
		std::cout << "Dog's second idea: " << dog1->getIdea(1) << std::endl;
		dog1->setIdea(1, "Ball is my best friend");
		std::cout << "Dog's second idea: " << dog1->getIdea(1) << std::endl;
		std::cout << std::endl;

		//Testing Assimnet operator
		Dog *dog2 = new Dog();
		*dog2 = *dog1;
		std::cout << "Dog's first idea: " << dog2->getIdea(0) << std::endl;
		std::cout << "Dog's second idea: " << dog2->getIdea(1) << std::endl;
		std::cout << std::endl;

		//Testing copy constuctor
		Dog *dog3 = new Dog(*dog1);
		std::cout << "Dog's first idea: " << dog3->getIdea(0) << std::endl;
		std::cout << "Dog's second idea: " << dog3->getIdea(1) << std::endl;
		std::cout << std::endl;

		delete dog1;
		delete dog2;
		delete dog3;
		std::cout << std::endl;
	}
	{
		const int N = 50;
		Animal* animals[N];

		for (int i = 0; i < N; ++i)
		{
			if (i < N / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		for (int i = 0; i < N; ++i)
			animals[i]->makeSound();

		for (int i = 0; i < N; ++i)
		{
			delete animals[i];
		}
	}

	return EXIT_SUCCESS;
}