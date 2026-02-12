#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main(void)
{
	// Test 1: Create a valid form
	std::cout << "Test 1: Creating a valid form" << std::endl;
	try
	{
		Form f1("Tax Form", 50, 100);
		std::cout << f1 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 2: Create form with highest grades (1)
	std::cout << "Test 2: Creating form with highest grades (1, 1)" << std::endl;
	try
	{
		Form f2("President's Decree", 1, 1);
		std::cout << f2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 3: Create form with lowest grades (150)
	std::cout << "Test 3: Creating form with lowest grades (150, 150)" << std::endl;
	try
	{
		Form f3("Intern Task", 150, 150);
		std::cout << f3 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 4: Form grade too high for signing (0)
	std::cout << "Test 4: Creating form with grade too high to sign (0)" << std::endl;
	try
	{
		Form f4("Invalid Form", 0, 100);
		std::cout << "Should have thrown GradeTooHighException" << std::endl;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Wrong exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 5: Form grade too low for execution (151)
	std::cout << "Test 5: Creating form with grade too low to execute (151)" << std::endl;
	try
	{
		Form f5("Invalid Form", 50, 151);
		std::cout << "Should have thrown GradeTooLowException" << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Wrong exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 6: Bureaucrat successfully signs a form
	std::cout << "Test 6: Bureaucrat with grade 50 signs form requiring grade 75" << std::endl;
	try
	{
		Bureaucrat b1("Alice", 50);
		Form f6("Document A", 75, 100);
		std::cout << "Created: " << b1 << std::endl;
		std::cout << "Created: " << f6 << std::endl;
		b1.signForm(f6);
		std::cout << "After signing: " << f6 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 7: Bureaucrat fails to sign - grade too low
	std::cout << "Test 7: Bureaucrat with grade 100 tries to sign form requiring grade 50" << std::endl;
	try
	{
		Bureaucrat b2("Bob", 100);
		Form f7("Document B", 50, 75);
		std::cout << "Created: " << b2 << std::endl;
		std::cout << "Created: " << f7 << std::endl;
		b2.signForm(f7);
		std::cout << "After attempt: " << f7 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 8: Bureaucrat with exact required grade signs form
	std::cout << "Test 8: Bureaucrat with grade 50 signs form requiring exactly grade 50" << std::endl;
	try
	{
		Bureaucrat b3("Charlie", 50);
		Form f8("Document C", 50, 100);
		std::cout << "Created: " << b3 << std::endl;
		std::cout << "Created: " << f8 << std::endl;
		b3.signForm(f8);
		std::cout << "After signing: " << f8 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 9: Highest grade bureaucrat signs any form
	std::cout << "Test 9: Bureaucrat with highest grade (1) signs form requiring grade 150" << std::endl;
	try
	{
		Bureaucrat b4("Diana", 1);
		Form f9("Document D", 150, 150);
		std::cout << "Created: " << b4 << std::endl;
		std::cout << "Created: " << f9 << std::endl;
		b4.signForm(f9);
		std::cout << "After signing: " << f9 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 10: Lowest grade bureaucrat cannot sign high-grade form
	std::cout << "Test 10: Bureaucrat with lowest grade (150) tries to sign form requiring grade 1" << std::endl;
	try
	{
		Bureaucrat b5("Eve", 150);
		Form f10("Document E", 1, 1);
		std::cout << "Created: " << b5 << std::endl;
		std::cout << "Created: " << f10 << std::endl;
		b5.signForm(f10);
		std::cout << "After attempt: " << f10 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 11: Form copy constructor
	std::cout << "Test 11: Form copy constructor" << std::endl;
	try
	{
		Form f11("Original Form", 75, 100);
		Form f11_copy(f11);
		std::cout << "Original: " << f11 << std::endl;
		std::cout << "Copy: " << f11_copy << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 12: Multiple bureaucrats trying to sign the same form
	std::cout << "Test 12: Multiple bureaucrats attempting to sign the same form" << std::endl;
	try
	{
		Bureaucrat b6("Frank", 90);
		Bureaucrat b7("Grace", 60);
		Form f12("Petition", 60, 100);
		std::cout << "Created: " << b6 << std::endl;
		std::cout << "Created: " << b7 << std::endl;
		std::cout << "Created: " << f12 << std::endl;
		b6.signForm(f12);
		std::cout << "- After first attempt: " << f12 << std::endl;
		b7.signForm(f12);
		std::cout << "- After second attempt: " << f12 << std::endl;
		b7.signForm(f12);
		std::cout << "- After third attempt: " << f12 << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}