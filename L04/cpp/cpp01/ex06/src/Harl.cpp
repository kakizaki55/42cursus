#include "Harl.hpp"

Harl::Harl() {
	// Constructor implementation (if needed)
}

Harl::~Harl() {
	// Destructor implementation (if needed)
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level)
{

	struct HarlLevels {
		std::string name;
		void (Harl::*func)();
	};

	HarlLevels levels[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	bool found = false;

	for (int i = 0; i < 4; ++i)
	{
		if (levels[i].name == level)
			found = true;
		if(found)
		{
			void (Harl::*funcPtr)() = levels[i].func;
			(this->*funcPtr)();
			std::cout << std::endl;
		}
	}
	if(!found)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}