#include <iostream>

class IntPair
{
public:
    IntPair() {}
    IntPair(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void set(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void print() const
    {
        std::cout << "Pair(" << x << ", " << y << ")" << std::endl;
    }

private:
    int x{};
    int y{};
};

int main()
{
    IntPair p1;
    p1.set(1, 1);

    IntPair p2{2, 2};

    IntPair p3{};

    p1.print();
    p2.print();
    p3.print();

    return 0;
}