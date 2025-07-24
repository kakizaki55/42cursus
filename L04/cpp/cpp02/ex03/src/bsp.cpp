#include <iostream>
#include "../include/bsp.hpp"
#include <stdio.h>
#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

Fixed barycentric_cords(Point const &v1, Point const &v2, Point const &point)
{
    return (point.getX() - v2.getX()) * (v1.getY() - v2.getY()) - (v1.getX() - v2.getX()) * (point.getY() - v2.getY());
}

bool bsp (Point v1, Point v2, Point v3, Point point)
{
    Fixed d1, d2, d3;
    bool all_neg, all_pos;

    d1 = barycentric_cords(v1, v2, point);
    d2 = barycentric_cords(v2, v3, point);
    d3 = barycentric_cords(v3, v1, point);

    all_neg = (d1 < 0) && (d2 < 0) && (d3 < 0);
    all_pos = (d1 > 0) && (d2 > 0) && (d3 > 0);

    return all_neg || all_pos;
}