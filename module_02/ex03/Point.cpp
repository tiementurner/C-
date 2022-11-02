#include "Point.hpp"

Point::Point() : 
                x(0), y(0){}

Point::~Point(){}

Point::Point(const float x, const float y) :
                                            x(x), y(y){}

Point& Point::operator=(const Point &p)
{
    return *this;
}