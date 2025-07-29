#include "../include/Fixed.hpp"
#include <iostream>
#include <stdio.h>

Fixed:: Fixed()
{
	this->_value = 0;
}

Fixed:: Fixed(const Fixed &other)
{
	*this = other;
}

Fixed:: Fixed(const  int &number_as_int)
{
	int fixed = number_as_int << _fractionalBits;
	this->_value = fixed;
}

Fixed:: Fixed(const float &number_as_float)
{
	int fixed = (number_as_float * float ((int)1 << _fractionalBits) + (number_as_float >= 0 ? 0.5 : -0.5));
	this->_value = fixed;
}

Fixed:: ~Fixed() { }

Fixed &Fixed::operator=(const Fixed &other)
{
	if(this != &other)
	{
		this->_value = other.getRawBits();
	}
	return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
	bool res = this->getRawBits() > other.getRawBits();
	return res;
}

bool Fixed::operator<(const Fixed &other) const
{
	bool res = this->getRawBits() < other.getRawBits();
	return res;
}

bool Fixed::operator>=(const Fixed &other) const
{
	bool res = this->getRawBits() >= other.getRawBits();
	return res;
}

bool Fixed::operator<=(const Fixed &other) const
{
	bool res = this->getRawBits() <= other.getRawBits();
	return res;
}

bool Fixed::operator==(const Fixed &other) const
{
	bool res = this->getRawBits() == other.getRawBits();
	return res;
}

bool Fixed::operator!=(const Fixed &other) const
{
	bool res = this->getRawBits() != other.getRawBits();
	return res;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() + other.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() - other.getRawBits());
	return res;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed res;
	int raw = this->getRawBits() * other.getRawBits();
	res.setRawBits(raw >> _fractionalBits);
	return res;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed res;
	int raw = this->getRawBits() << _fractionalBits / other.getRawBits();
	res.setRawBits(raw);
	return res;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return temp;
}

Fixed& Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return temp;
}

Fixed& Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed:: setRawBits(int const raw)
{
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

Fixed Fixed:: max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}

Fixed Fixed:: min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

std::ostream& operator<< (std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return output;
}
