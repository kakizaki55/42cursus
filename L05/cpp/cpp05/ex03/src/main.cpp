#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main(void)
{

	Bureaucrat boss = Bureaucrat("Boss", 1);
	Intern intern;
	AForm* form;

	try
	{
		form = intern.makeForm("robotomy request", "bender");

		if (form)
		{
			std::cout << *form << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
		else
		{
			std::cout << "Form creation failed." << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}