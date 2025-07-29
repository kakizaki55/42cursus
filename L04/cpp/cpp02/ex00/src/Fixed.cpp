#include <Fixed.hpp>
#include <iostream>

Fixed:: Fixed()
{
	this->_value = 0;
	std:: cout << "Default constuctor called \n";
}

Fixed:: Fixed(const Fixed &other)
{
	std:: cout << "Copy constuctor called \n";
	*this = other;
}

Fixed:: ~Fixed()
{
	std:: cout << "Destructor called \n";
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called \n";
	if(this != &other)
	{
		this->_value = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called \n";
	return this->_value;
}

void Fixed:: setRawBits(int const raw)
{
	std::cout << "setRawBits member function called \n";
	this->_value = raw;
}
