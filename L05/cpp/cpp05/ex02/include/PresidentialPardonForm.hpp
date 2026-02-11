
#pragma once

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	// Constructors / Destructor
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();

	// Getters
	const std::string &getTarget() const;

	// Core
	virtual void execute(Bureaucrat const &executor) const;

private:
	PresidentialPardonForm();

	std::string _target;

	static const int _signGrade = 25;
	static const int _execGrade = 5;
};
