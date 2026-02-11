#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat    bob("Bob", 42);
	Bureaucrat    alice("Alice", 150);
	AForm*        form;

	// try
	// {
	// 	form = new ShrubberyCreationForm("home");
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




	return 0;
}