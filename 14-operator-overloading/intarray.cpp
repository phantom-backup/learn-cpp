#include <algorithm>
#include <cassert>
#include <iostream>

class IntArray
{
private:
    std::size_t size{ 0 };
    int* data{ nullptr };

public:
    IntArray(std::size_t size) : size{ size }, data{ size ? new int[size] {} : nullptr }
    {
    }

    IntArray(const IntArray& other) : size{ other.size }, data{ size ? new int[size] : nullptr }
    {
        std::copy(other.data, other.data + size, data);
    }

    IntArray& operator=(IntArray other)
    {
        swap(*this, other);
        return *this;
    }

    friend void swap(IntArray& a, IntArray& b)
    {
        using std::swap;

        swap(a.size, b.size);
        swap(a.data, b.data);
    }

    ~IntArray()
    {
        delete[] data;
    }

    int& operator[](std::size_t i)
    {
        assert(i < size);
        return data[i];
    }

    friend std::ostream& operator<<(std::ostream& out, const IntArray& intArray)
    {
        for (int i{ 0 }; i < intArray.size - 1; ++i)
        {
            out << intArray.data[i] << " ";
        }

        out << intArray.data[intArray.size - 1];
        return out;
    }
};

IntArray fillArray()
{
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main()
{
    IntArray a{ fillArray() };

    std::cout << a << '\n';

    auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
    a = ref;

    IntArray b(1);
    b = a;

    a[4] = 7;

    std::cout << b << '\n';

    return 0;
}