
#pragma once

#ifndef FIXED_HPP
# define FIXED_HPP


// #ifndef PRINT_BITS
#define PRINT_BITS true
#define FRACTINAL_BITS 8

#include <iostream>

class Fixed
{
	//private fucntion go here
	private:
	//fixed point number value
	int _value;
	//fractinal bits
	static const int _fractionalBits = 16;
	//ppblic fucntion go here
	public:
		// constructor
		Fixed();
		//copy constuctor
		Fixed(const Fixed &other);
		Fixed(const int &intiger);
		Fixed(const float &number_as_float);
		// destructor
		~Fixed();
		// assignment operator
		Fixed &operator=(const Fixed &other);
		//Math operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		// Fixed &operator<<(void);

		// member functions
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

// this is for printing to ostream ( not allowed to be a member function);
std::ostream& operator<< (std::ostream &output, const Fixed &fixed);

#endif