#include <cstdint>
#include <iostream>

class Average
{
private:
    std::int32_t sum{ 0 };
    std::int8_t count{0};

public:
    Average& operator+=(int num)
    {
        sum += num;
        ++count;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Average& average)
    {
        out << (average.count != 0 ? static_cast<double>(average.sum) / average.count : 0);
        return out;
    }
};

int main()
{
    Average avg{};

    avg += 4;
    std::cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n'; // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10;         // 2 calls chained together
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy{ avg };
    std::cout << copy << '\n';

    return 0;
}