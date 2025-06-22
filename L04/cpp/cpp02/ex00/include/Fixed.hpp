
#pragma once

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	//private fucntion go here
	private:
	//fixed point number value
	int _value;
	//fractinal bits
	static const int _fractionalBits = 8;
	//ppblic fucntion go here
	public:
		// constructor
		Fixed();
		//copy constuctor
		Fixed(const Fixed &other);
		// // destructor
		~Fixed();
		// assignment operator
		Fixed &operator=(const Fixed &other);

		// member functions
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif