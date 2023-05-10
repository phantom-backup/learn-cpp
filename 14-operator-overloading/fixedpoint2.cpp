#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>

class FixedPoint2
{
private:
    std::int16_t base{};
    std::int8_t fraction{};

public:
    FixedPoint2(std::int16_t base = 0, std::int8_t fraction = 0) : base{ base }, fraction{ fraction }
    {
        if (base < 0 || fraction < 0)
        {
            if (base > 0)
            {
                base = -base;
            }

            if (fraction > 0)
            {
                fraction = -fraction;
            }
        }

        if (fraction > 99 && fraction < -99)
        {
            base += fraction / 100;
            fraction = fraction % 100;
        }
    }

    FixedPoint2(double decimal)
        : base{ static_cast<std::int16_t>(std::trunc(decimal)) },
        fraction{ static_cast<std::int8_t>(std::round(decimal * 100) - base * 100) }
    {
    }

    operator double() const
    {
        return base + fraction / 100.0;
    }
};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& fixedPoint2)
{
    out << static_cast<double>(fixedPoint2);
    return out;
}

void operator>>(std::istream& in, FixedPoint2& fixedPoint2)
{
    double decimal{};
    in >> decimal;
    fixedPoint2 = FixedPoint2{ decimal };
}

void testAddition()
{
    // h/t to reader Sharjeel Safdar for this function
    std::cout << std::boolalpha;
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{1.23} == FixedPoint2{1.98}) << '\n';    // both positive, no decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{1.50} == FixedPoint2{2.25}) << '\n';    // both positive, with decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{-1.23} == FixedPoint2{-1.98}) << '\n'; // both negative, no decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{-1.50} == FixedPoint2{-2.25}) << '\n'; // both negative, with decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{-1.23} == FixedPoint2{-0.48}) << '\n';  // second negative, no decimal overflow
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{-1.50} == FixedPoint2{-0.75}) << '\n';  // second negative, possible decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{1.23} == FixedPoint2{0.48}) << '\n';   // first negative, no decimal overflow
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{1.50} == FixedPoint2{0.75}) << '\n';   // first negative, possible decimal overflow
}

int main()
{
    testAddition();

    FixedPoint2 a{ -0.48 };
    std::cout << a << '\n';

    std::cout << -a << '\n';

    std::cout << "Enter a number: "; // enter 5.678
    std::cin >> a;

    std::cout << "You entered: " << a << '\n';

    return 0;
}