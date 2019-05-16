#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Point2d.hpp"
#include <fstream>
#include <string>
using namespace std;

class Circle
{
private:
    Point2d center;
    string color;
    double radius;
public:
    friend istream& operator >>(istream& in, Circle& circle);
    friend ostream& operator <<(ostream& out, const Circle& circle);
	friend bool hasOverlap(const Circle& c1, const Circle& c2);

    Circle();
    Circle(double x, double y, double radius, string color);

    Point2d getCenter() const;
    string getColor() const;
    void setColor(string inColor);
    double getRadius() const;
    void setRadius(double rad);
    void setCenter(Point2d c);
    bool contains(const Point2d& point) const;
};


#endif // CIRCLE_HPP
