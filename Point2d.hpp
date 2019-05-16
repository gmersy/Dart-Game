#ifndef POINT2D_HPP
#define POINT2D_HPP

#include <iostream>
using namespace std;

class Point2d
{
private:
    double x, y;
public:
    friend istream& operator >>(istream& in, Point2d& point);
	friend ostream& operator <<(ostream& out, const Point2d& point);
	friend double pointDist(const Point2d& p1, const Point2d& p2);

    Point2d();
    Point2d(double x, double y);

    double getX() const;
    double getY() const;
    void set(double x, double y);
};

#endif // POINT2D_HPP
