#include <iostream>
#include <cmath>
#include "Point2d.hpp"

using namespace std;

istream& operator >>(istream& in, Point2d& point)
{
    in >> point.x >> point.y;
    return in;
}

ostream& operator <<(ostream& out, const Point2d& point)
{
	out << "(" << point.x << ", " << point.y << ")";
	return out;
}

Point2d::Point2d()
{
    x = 0;
    y = 0;
}

Point2d::Point2d(double inX, double inY)
{
    x = inX;
    y = inY;
}

double Point2d::getX() const
{
    return x;
}

double Point2d::getY() const
{
    return y;
}

double pointDist(const Point2d& p1, const Point2d& p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void Point2d::set(double x, double y)
{
    this->x = x;
    this->y = y;
}
