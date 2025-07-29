#include "../include/Fixed.hpp"
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

Fixed:: Fixed(const  int &number_as_int)
{
	std::cout << "Int constructor called" << std::endl;
	int fixed = number_as_int << _fractionalBits;
	this->_value = fixed;
}
Fixed:: Fixed(const float &number_as_float)
{
	std::cout << "Float constructor called" << std::endl;
	int fixed = (number_as_float * float ((int)1 << _fractionalBits) + (number_as_float >= 0 ? 0.5 : -0.5));
	this->_value = fixed;
}

Fixed:: ~Fixed()
{
	std:: cout << "Destructor called \n";
}

Fixed &Fixed::operator= (const Fixed &other)
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

int Fixed:: toInt(void) const
{
	int res;
	int raw = getRawBits();
	int offset = 1 << (_fractionalBits - 1);
	if (raw >= 0)
		res = (raw + offset) >> _fractionalBits;
	else
		res = (raw - offset) >> _fractionalBits;
	return res;
}

float Fixed:: toFloat(void) const
{
	float res;
	res = static_cast<float>(getRawBits()) / (1 << _fractionalBits);
	return res;
}


void printBits(std::ostream& output, unsigned frac, int bits) {
	if (bits == 0)
		return;
	output << ((frac & (1 << (bits - 1))) ? '1' : '0');
	printBits(output, frac, bits - 1);
}

std::ostream& operator<< (std::ostream& output, const Fixed& fixed)
{
	output << fixed.toFloat();
	return output;
}
