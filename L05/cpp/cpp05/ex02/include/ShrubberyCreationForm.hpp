#pragma once

#include "../include/AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor) const;

    class FileCreationException : public std::exception
    {
    	public:
        	virtual const char* what() const throw();
    };

	class FileAlreadyExistsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};
