#include "Fixed.hpp"

class Point
{
    public:
    Point();
    ~Point();
    Point(const float x, const float y);
    Point(const Point &p);
    Point& operator=(const Point &p);

    private:
    Fixed const x;
    Fixed const y;
};