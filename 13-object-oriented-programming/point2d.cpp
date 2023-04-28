#include <cmath>
#include <iostream>

class Point2d
{
public:
    Point2d() = default;

    Point2d(double x, double y) : x{x}, y{y} {}

    double distanceTo(Point2d p) const
    {
        return std::sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
    }

    void print() const
    {
        std::cout << "Point2d(" << x << ", " << y << ")" << std::endl;
    }

    friend double distanceFrom(Point2d start, Point2d end);

private:
    double x{0.0};
    double y{0.0};
};

double distanceFrom(Point2d start, Point2d end)
{
    return std::sqrt((end.x - start.x) * (end.x - start.x) +
                     (end.y - start.y) * (end.y - start.y));
}

int main()
{
    Point2d first{};
    Point2d second{3.0, 4.0};
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}