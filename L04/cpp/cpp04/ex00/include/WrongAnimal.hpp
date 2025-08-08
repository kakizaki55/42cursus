#pragma once
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
		void setType(const std::string &type);

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		~WrongAnimal();

		WrongAnimal &operator=(const WrongAnimal &other);
		std::string getType() const;

		void makeSound() const;
};
