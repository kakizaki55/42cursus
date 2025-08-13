#include "../include/Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Default Brain constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		ideas[i] = "";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Copy Brain constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Assignment operator for Brain called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
	{
		ideas[index] = idea;
		std::cout << "Idea set at index " << index << ": " << idea << std::endl;
	}
	else
	{
		std::cerr << "Index out of bounds" << std::endl;
	}
}
std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return ideas[index];
	}
	else
	{
		std::cerr << "Index out of bounds" << std::endl;
		return "";
	}
}