#include <iostream>
#include"./include/Fixed.hpp"




int main( void )
{
	Fixed a = -10.5001f;
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
		puts("a and b are the same");
	if(a != b)
		puts("a and b are not the same");


}