#include <iostream>

class Point3d
{
public:
    void setValues(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    bool isEqual(const Point3d &other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }

    void print() const
    {
        std::cout << "<" << x << ", " << y << ", " << z << ">";
    }

private:
    int x{};
    int y{};
    int z{};
};

int main()
{
    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 3);

    if (point1.isEqual(point2))
    {
        std::cout << "point1 and point2 are equal" << std::endl;
    }
    else
    {
        std::cout << "point1 and point2 are not equal" << std::endl;
    }

    Point3d point3;
    point3.setValues(3, 4, 5);

    if (point1.isEqual(point3))
    {
        std::cout << "point1 and point3 are equal" << std::endl;
    }
    else
    {
        std::cout << "point1 and point3 are not equal" << std::endl;
    }

    return 0;
}