#include <iostream>
#include"../include/Fixed.hpp"
#include<stdio.h>
#include <climits>



int main( void )
{
	Fixed a = 123671928312.5001f;
	Fixed b = 10.5001f;

	Fixed c(0.5f);
	Fixed d(0.0000001f);

	std::cout << "a :"<<  a << std::endl;
	// why does this turn in to 0.00390625


	std::cout << "b :" << b << std::endl;
	std::cout << "c :"<< c << std::endl;
	std::cout << "d :"<< d << std::endl;

	if(a > b)
	{
		puts("a is biggger then b");
	}
	if(b > a)
	{
		puts("b is bigger then a");
	}

	if(a == b && a >= b && a <=b)
		puts("a and b are the same\n");
	if(a != b)
		puts("a and b are not the same\n");

	// Fixed a;
	// Fixed const b( INT_MAX );
	// Fixed const c( 42.42f );
	// Fixed const d( b ); 
	// a = Fixed( 1234.3f );
	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;
	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;


	// puts("==================================\n");
	
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
		std::cout << Fixed::min( a, b ) << std::endl;
	}
	
	// puts("==================================\n");

}