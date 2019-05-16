#include "Point2d.hpp"
#include "Circle.hpp"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


istream& operator >>(istream& in, Circle& circle)
{
    in >> circle.center >> circle.radius >> circle.color;
    return in;
}

ostream& operator <<(ostream& out, const Circle& circle)
{
	out << "["<<circle.color << " c=" << circle.center << " r="  << circle.radius<<"]";
	return out;
}

bool hasOverlap(const Circle& c1, const Circle& c2)
{
	return pointDist(c1.center, c2.center) < (c1.radius + c2.radius);
}

Circle::Circle(): center(0,0), color("none")
{
	radius = 0;
}

Circle::Circle(double x, double y, double inRadius, string inColor): center(x, y), color(inColor)
{
	radius = inRadius;
}

Point2d Circle::getCenter() const
{
    return center;
}

string Circle::getColor() const
{
    return color;
}

void Circle::setColor(string inColor)
{
	color = inColor;
}

double Circle::getRadius() const
{
    return radius;
}

bool Circle::contains(const Point2d& point) const
{
    return pointDist(center, point) <= radius;
    return pointDist(center, point) <= radius;
}

void Circle::setRadius(double rad)
{
    radius = rad;
}
void Circle::setCenter(Point2d c)
{
    center = c;
}
