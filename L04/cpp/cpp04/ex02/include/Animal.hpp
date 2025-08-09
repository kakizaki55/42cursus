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
		
		virtual void makeSound() const = 0;
		std::string getType() const;
};
