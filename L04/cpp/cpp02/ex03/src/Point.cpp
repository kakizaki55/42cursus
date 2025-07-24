#include "../include/Point.hpp"
#include <iostream>

Point::Point() : x(0), y(0) { }

Point::Point(const Point &other) : x(other.x), y(other.y) { }

Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) { }

Point::~Point() { }

Point &Point::operator=(const Point &other) 
{
    std::cout << "Point assignment operator called" << std::endl;
    if (this != &other) {
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

Fixed Point::getX() const 
{
    return this->x;
}

Fixed Point::getY() const 
{
    return this->y;
}

bool Point::operator==(const Point &other) const 
{
    return (this->x == other.x && this->y == other.y);
}

bool Point::operator!=(const Point &other) const 
{
    return !(*this == other);
}
