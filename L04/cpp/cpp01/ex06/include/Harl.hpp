#include <iostream>
#include <string>
#include <stdlib.h>

#pragma once

// struct HarlLevels 
// {
// 		std::string name;
// 		void (Harl::*func)();
// };

enum Level 
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	NOT_FOUND
};
class Harl
{
	private:

		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:

		Harl();
		~Harl();
		void complain(std::string level);
};
