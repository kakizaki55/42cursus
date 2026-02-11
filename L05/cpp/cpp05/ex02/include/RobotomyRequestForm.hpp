#pragma once

# include "../include/AForm.hpp"
# include <string>

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	static const int _signGrade = 72;
	static const int _execGrade = 45;
	RobotomyRequestForm();

public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	void execute(Bureaucrat const & executor) const;
};

