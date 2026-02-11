#include "../include/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);

	std::cout << "*BZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ*" << std::endl;
	std::cout << "*WHIRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR*" << std::endl;
	std::cout << "*CLANKCLANKCLANKCLANKCLANKCLANKCLANKCLANKCLANKCLANKCLANKCLANKCLANKCL*" << std::endl;

	int random = rand() % 2;

	if (random == 0)
	{
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "The robotomy on " << _target << " failed." << std::endl;
	}
}
