#include <iostream>
#include"../include/Fixed.hpp"
#include "../include/Point.hpp"
#include "../include/bsp.hpp"
#include<stdio.h>

int main( void )
{
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(10), Fixed(0));
	Point c(Fixed(0), Fixed(10));

	if(bsp(a, b, c, Point(0.2f, 0.1f)))
	{
		printf("Point is inside the triangle\n");
	}
	else
	{
		printf("Point is outside the triangle\n");
	}
}
