#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main(void)
{
	// Bureaucrat    bob("Bob", 42);
	// Bureaucrat    alice("Alice", 150);
	// AForm*        form;

	// try
	// {
	// 	form = new ShrubberyCreationForm("garden");
	// 	bob.signForm(*form);
	// 	bob.executeForm(*form);
	// 	alice.executeForm(*form);
	// 	delete form;
	// }
	// catch (std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	// try
	// {
	// 	form = new RobotomyRequestForm("person");
	// 	bob.signForm(*form);
	// 	bob.executeForm(*form);
	// 	alice.executeForm(*form);
	// 	delete form;
	// }
	// catch (std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	// Bureaucrat    president ("President", 1);
	// try
	// {

	// 	form = new PresidentialPardonForm("criminal");
	// 	bob.signForm(*form);
	// 	bob.executeForm(*form);
	// 	alice.executeForm(*form);
	// 	president.signForm(*form);
	// 	president.executeForm(*form);
	// 	delete form;
	// }
	// catch (std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

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
	std::cout << std::endl;
	return 0;
}