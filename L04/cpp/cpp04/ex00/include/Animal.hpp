#pragma once
#include <string>

class Animal
{
	protected:
		std::string type;
		void setType(const std::string &type);

	public:
		Animal();
		Animal(const Animal &other);
		virtual ~Animal();

		Animal &operator=(const Animal &other);
		std::string getType() const;

		virtual void makeSound() const;
};
