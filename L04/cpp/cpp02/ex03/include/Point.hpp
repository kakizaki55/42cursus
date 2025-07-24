#include "./Fixed.hpp"

#pragma once

class Point
{
    private:

        Fixed x;
        Fixed y;

    public:

        Point();
        Point(const Point &other);
        Point(const Fixed &x, const Fixed &y);
        ~Point();

        Point &operator=(const Point &other);

        Fixed getX() const;
        Fixed getY() const;

        bool operator==(const Point &other) const;
        bool operator!=(const Point &other) const;
};
