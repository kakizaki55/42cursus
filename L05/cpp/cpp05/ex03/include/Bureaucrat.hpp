#pragma once

# include <string>
# include <exception>
# include <iostream>

class AForm;

class Bureaucrat
{
private:
	const std::string   _name;
	int                 _grade;

	static const int    _highestGrade = 1;
	static const int    _lowestGrade = 150;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string&  getName() const;
	int                 getGrade() const;

	void                incrementGrade();
	void                decrementGrade();
	void                signForm(AForm& form);
	void                executeForm(AForm const & form);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
