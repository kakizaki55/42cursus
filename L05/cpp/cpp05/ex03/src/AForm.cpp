#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < _highestGrade || gradeToExecute < _highestGrade)
		throw GradeTooHighException();
	if (gradeToSign > _lowestGrade || gradeToExecute > _lowestGrade)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << "Form: " << form.getName()
		<< ", Signed: " << (form.isSigned() ? "yes" : "no")
		<< ", Grade to sign: " << form.getGradeToSign()
		<< ", Grade to execute: " << form.getGradeToExecute();
	return out;
}
