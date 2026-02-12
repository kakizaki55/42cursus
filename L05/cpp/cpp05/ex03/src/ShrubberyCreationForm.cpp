#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", _signGrade, _execGrade), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);

	std::string filename = _target + "_shrubbery";
	std::ifstream existCheck(filename.c_str());
	if (existCheck.is_open()) {
		existCheck.close();
		throw FileAlreadyExistsException();
	}
	existCheck.close();

	filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open()) {
		throw FileCreationException();
	}

	file << "         ccee88oo\n";
	file << "      C8O8O8Q8PoOb o8oo\n";
	file << "   dOB69QO8PdUOpugoO9bD\n";
	file << "  CgggbU8OU qOp qOdoUOdcb\n";
	file << "      6OuU  /p u gcoUodpP\n";
	file << "        \\\\//  /douUP\n";
	file << "          \\\\////\n";
	file << "           |||/\\\n";
	file << "           |||\\/\n";
	file << "           |||||\n";
	file << "     .....//||||\\....\n";
	file << "\n";

	file.close();
}


const char* ShrubberyCreationForm::FileCreationException::what() const throw()
{
    return "Could not create file";
}

const char* ShrubberyCreationForm::FileAlreadyExistsException::what() const throw()
{
	return "File already exists";
}