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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl << std::endl;
	std::cout << "I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std:: endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}
Level convert(const std:: string& level)
{
	if(level.compare("DEBUG") == 0) return DEBUG;
	if(level.compare("INFO") == 0) return INFO;
	if(level.compare("WARNING") == 0) return WARNING;
	if(level.compare("ERROR") == 0) return ERROR;
	return NOT_FOUND;
}
void Harl::complain(std::string level)
{
	Level current_level = convert(level);
	switch (current_level)
	{
		case DEBUG :
			this->debug();
		case INFO :
			this->info();
		case WARNING :
			this->warning();
		case ERROR :
			this->error();
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std :: endl;
	}
}
