
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

		Fixed &operator=(const Fixed &other);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream& operator<< (std::ostream& output, const Fixed& fixed);
