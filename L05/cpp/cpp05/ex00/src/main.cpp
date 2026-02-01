#include "../include/Bureaucrat.hpp"

int main(void)
{
	std::cout << "=== Bureaucrat Test Cases ===" << std::endl << std::endl;

	// Test 1: Create a valid bureaucrat
	std::cout << "Test 1: Creating a valid bureaucrat" << std::endl;
	try
	{
		Bureaucrat b1("Alice", 50);
		std::cout << "" << b1 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 2: Create bureaucrat with highest grade (1)
	std::cout << "Test 2: Creating bureaucrat with highest grade (1)" << std::endl;
	try
	{
		Bureaucrat b2("Bob", 1);
		std::cout << "" << b2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 3: Create bureaucrat with lowest grade (150)
	std::cout << "Test 3: Creating bureaucrat with lowest grade (150)" << std::endl;
	try
	{
		Bureaucrat b3("Charlie", 150);
		std::cout << "" << b3 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 4: Grade too high exception (0)
	std::cout << "Test 4: Creating bureaucrat with grade too high (0)" << std::endl;
	try
	{
		Bureaucrat b4("David", 0);
		std::cout << "Should have thrown GradeTooHighException" << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Wrong exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 5: Grade too high exception (-5)
	std::cout << "Test 5: Creating bureaucrat with grade too high (-5)" << std::endl;
	try
	{
		Bureaucrat b5("Eve", -5);
		std::cout << "Should have thrown GradeTooHighException" << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Wrong exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 6: Grade too low exception (151)
	std::cout << "Test 6: Creating bureaucrat with grade too low (151)" << std::endl;
	try
	{
		Bureaucrat b6("Frank", 151);
		std::cout << "Should have thrown GradeTooLowException" << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Wrong exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 7: Grade too low exception (200)
	std::cout << "Test 7: Creating bureaucrat with grade too low (200)" << std::endl;
	try
	{
		Bureaucrat b7("Grace", 200);
		std::cout << "Should have thrown GradeTooLowException" << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Wrong exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 8: Increment grade
	std::cout << "Test 8: Incrementing grade from 50 to 49" << std::endl;
	try
	{
		Bureaucrat b8("Henry", 50);
		std::cout << "Before: " << b8 << std::endl;
		b8.incrementGrade();
		std::cout << "After: " << b8 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 9: Decrement grade
	std::cout << "Test 9: Decrementing grade from 50 to 51" << std::endl;
	try
	{
		Bureaucrat b9("Iris", 50);
		std::cout << "Before: " << b9 << std::endl;
		b9.decrementGrade();
		std::cout << "After: " << b9 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 10: Increment at highest grade (should fail)
	std::cout << "Test 10: Incrementing grade at highest (1) - should fail" << std::endl;
	try
	{
		Bureaucrat b10("Jack", 1);
		std::cout << "Created: " << b10 << std::endl;
		b10.incrementGrade();
		std::cout << "Should have thrown GradeTooHighException" << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Wrong exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 11: Decrement at lowest grade (should fail)
	std::cout << "Test 11: Decrementing grade at lowest (150) - should fail" << std::endl;
	try
	{
		Bureaucrat b11("Kate", 150);
		std::cout << "Created: " << b11 << std::endl;
		b11.decrementGrade();
		std::cout << "Should have thrown GradeTooLowException" << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Wrong exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 12: Copy constructor
	std::cout << "Test 12: Copy constructor" << std::endl;
	try
	{
		Bureaucrat b12("Liam", 75);
		Bureaucrat b12_copy(b12);
		std::cout << "Original: " << b12 << std::endl;
		std::cout << "Copy: " << b12_copy << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 13: Assignment operator
	std::cout << "Test 13: Assignment operator" << std::endl;
	try
	{
		Bureaucrat b13a("Mia", 25);
		Bureaucrat b13b("Noah", 100);
		std::cout << "Before: b13a = " << b13a << ", b13b = " << b13b << std::endl;
		b13a = b13b;
		std::cout << "After: b13a = " << b13a << ", b13b = " << b13b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== All tests completed ===" << std::endl;
	return 0;
}