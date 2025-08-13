#pragma once
#include "../include/Animal.hpp"
#include "../include/Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	private:
		Brain *_brain;

	public:
		Dog();
		Dog(const Dog &other);
		~Dog();

		Dog &operator=(const Dog &other);

		virtual void makeSound() const;
		void setIdea(int index, const std::string &idea);
		std::string getIdea(int index) const;
};
