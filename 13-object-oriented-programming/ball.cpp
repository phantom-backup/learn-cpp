#include <iostream>
#include <string>

class Ball
{
public:
    Ball(double radius)
    {
        this->color = "black";
        this->radius = radius;
    }

    Ball(const std::string &color = "black", double radius = 10.0)
    {
        this->color = color;
        this->radius = radius;
    }

    void print() const
    {
        std::cout << "color: " << color << ", radius: " << radius << std::endl;
    }

private:
    std::string color{};
    double radius{};
};

int main()
{
    Ball def{};
    def.print();

    Ball blue{"blue"};
    blue.print();

    Ball twenty{20.0};
    twenty.print();

    Ball blueTwenty{"blue", 20.0};
    blueTwenty.print();

    return 0;
}