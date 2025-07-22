#include <iostream>
#include"../include/Fixed.hpp"
#include<stdio.h>



int main( void )
{
	Fixed a = -11.5001f;
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


	puts("==================================\n");

	// {
	// 	Fixed a = 10.01f;
	// 	Fixed b = 1.2f;

	// 	Fixed c = a + b;
	// 	std::cout << a  << " + " <<  b  << " is : " << c << std::endl;
	// 	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// 	std::cout << a << std::endl;
	// 	std::cout << ++a << std::endl;
	// 	std::cout << a << std::endl;
	// 	std::cout << a++ << std::endl;
	// 	std::cout << a << std::endl;
	// 	// std::cout << b << std::endl;
	// 	// std::cout << Fixed::max( a, b ) << std::endl;
	// }
	{

		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		// std::cout << a << std::endl;
		// std::cout << b << std::endl;
		// std::cout << Fixed::max( a, b ) << std::endl;
	}



}