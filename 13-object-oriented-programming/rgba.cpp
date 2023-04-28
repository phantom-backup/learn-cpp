#include <cstdint>
#include <iostream>

class RGBA
{
public:
    using Channel = std::uint8_t;

    RGBA(Channel red = 0, Channel blue = 0, Channel green = 0, Channel alpha = 255)
        : red{red}, blue{blue}, green{green}, alpha{alpha}
    {
    }

    void print() const
    {
        std::cout << "r=" << static_cast<int>(red) << " g=" << static_cast<int>(green)
                  << " b=" << static_cast<int>(blue) << " a=" << static_cast<int>(alpha) << std::endl;
    }

private:
    Channel red;
    Channel blue;
    Channel green;
    Channel alpha;
};

int main()
{
    RGBA teal{0, 127, 127};
    teal.print();

    return 0;
}