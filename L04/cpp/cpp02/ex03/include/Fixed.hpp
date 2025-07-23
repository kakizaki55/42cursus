#include <iostream>

#pragma once

class Fixed
{
	private:

		int _value;
		static const int _fractionalBits = 8;

	public:

		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int &intiger);
		Fixed(const float &number_as_float);
		~Fixed();

		//Assignment operator
		Fixed &operator=(const Fixed &other);

		//Math operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// Arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// Increment/decrement operators
		Fixed operator++(int);
		Fixed& operator++(void);
		Fixed operator--(int);
		Fixed& operator--(void);	

		// Member functions
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
		Fixed static max(const Fixed &a, const Fixed &b);
		Fixed static min(const Fixed &a, const Fixed &b);
};

std::ostream& operator<< (std::ostream &output, const Fixed &fixed);
