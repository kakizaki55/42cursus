#include "../include/Animal.hpp"
#include <iostream>
#pragma once

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();

		Dog &operator=(const Dog &other);

		virtual void makeSound() const;
};
